#pragma once

#include <fstream>
#include <span>
#include <vector>
#include <map>
#include <thread>
#include <mutex>
#include <condition_variable>

class ThreadSafeSeqFileWriter {
 public:
    ThreadSafeSeqFileWriter(const std::string& file_path, size_t batch_size)
        : file_stream_(file_path, std::ios::binary)
        , next_index_(0)
        , batch_size_(batch_size)
        , is_finished_(false) {
        writer_thread_ = std::thread(&ThreadSafeSeqFileWriter::ProcessQueue, this);
    }

    void Write(size_t index, std::span<char> packet_data) {
        std::lock_guard<std::mutex> lock(write_mutex_);
        packet_queue_[index] = std::vector<char>(packet_data.begin(), packet_data.end());
        write_cv_.notify_all();
    }

    void Finish() {
        std::lock_guard<std::mutex> lock(write_mutex_);
        is_finished_ = true;
        write_cv_.notify_all();
    }

    ~ThreadSafeSeqFileWriter() {
    Finish();
    if (writer_thread_.joinable()) {
        writer_thread_.join();
    }
    file_stream_.close();
    }

private:
    void ProcessQueue() {
        while (true) {
        std::vector<char> data;
        {
            std::unique_lock<std::mutex> lock(write_mutex_);
            write_cv_.wait(lock, [this] {
                return packet_queue_.count(next_index_) > 0 || is_finished_;
            });

            if (is_finished_ && packet_queue_.empty())
            break;

            if (packet_queue_.count(next_index_) > 0) {
                data = std::move(packet_queue_[next_index_]);
                packet_queue_.erase(next_index_);
                ++next_index_;
            }
        }
        if (!data.empty())
            file_stream_.write(data.data(), data.size());
        }
    }

    std::ofstream file_stream_;
    std::thread writer_thread_;
    std::mutex write_mutex_;
    std::condition_variable write_cv_;
    std::map<size_t, std::vector<char>> packet_queue_;
    size_t next_index_;
    size_t batch_size_;
    bool is_finished_;
};
