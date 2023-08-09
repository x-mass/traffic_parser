#include <thread>


template <typename Job>
class ThreadPool {
public:
    ThreadPool(int num_threads, Job&& job)
        : job_(std::forward<Job>(job)) {
        StartThreads(num_threads);
    }

    ~ThreadPool() {
        JoinThreads();
    }

private:
    Job job_;
    std::vector<std::thread> threads_;

    void StartThreads(int num_threads) {
        for (int i = 0; i < num_threads; ++i) {
        threads_.push_back(std::thread(job_));
        }
    }

    void JoinThreads() {
        for (auto& thread : threads_) {
            if (thread.joinable()) {
                thread.join();
            }
        }
    }
};
