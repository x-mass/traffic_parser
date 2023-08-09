#pragma once

#include <condition_variable>
#include <mutex>
#include <optional>
#include <queue>

template <typename T>
class BlockingMPMCQueue {
public:
    BlockingMPMCQueue() : is_terminated_(false) {}

    template <typename U>
    void push(U&& value) {
        std::lock_guard<std::mutex> lock(queue_mutex_);
        queue_.push(std::forward<U>(value));
        push_cv_.notify_one();
    }

    std::optional<T> pop() {
        std::unique_lock<std::mutex> lock(queue_mutex_);
        while (queue_.empty() && !is_terminated_) {
            push_cv_.wait(lock);
        }

        if (queue_.empty() && is_terminated_) {
            return std::nullopt;
        }

        T value = std::move(queue_.front());
        queue_.pop();
        return std::optional<T>(std::move(value));
    }

    bool empty() const {
        std::lock_guard<std::mutex> lock(queue_mutex_);
        return queue_.empty();
    }

    void terminate() {
        {
            std::lock_guard<std::mutex> lock(queue_mutex_);
            is_terminated_ = true;
        }
        push_cv_.notify_all();
    }

private:
    std::queue<T> queue_;
    mutable std::mutex queue_mutex_;
    std::condition_variable push_cv_;
    bool is_terminated_;
};
