#include <iostream>
#include <thread>
#include <vector>
#include <functional>
#include <mutex>
#include <queue>
#include <condition_variable>
#include <atomic>
#include <shared_mutex>

class ThreadPool final
{
    std::vector<std::thread> threads_;
    std::condition_variable condition_variable_;
    std::mutex mutex_;
    bool ended_;
    std::queue<std::function<void()>> tasks_;
public:
    ThreadPool(int num_thread) : ended_(false)
    {
        for(int i=0; i<num_thread; ++i)
        {
            threads_.emplace_back(
                [this]() {
                    while(true)
                    {
                        std::function<void()> task;
                        {
                            std::unique_lock<std::mutex> lock(mutex_);
                            condition_variable_.wait(lock, [this] { return ended_ || !tasks_.empty();});

                            if(ended_ && tasks_.empty())
                            {
                                return;
                            }
                            task = tasks_.front();
                            tasks_.pop();
                        }
                        task();
                    }
                }
            );
        }
    }

    template<class F, class... Args>
    void enqueue(F& func, Args&... args)
    {
        {
            // std::lock_guard<std::mutex> lock(mutex_);
            std::unique_lock<std::mutex> lock(mutex_);
            auto task = std::bind(std::forward<F>(func), std::forward<Args>(args)...);
            // auto task = func;
            // auto task = std::bind(func, args...);
            tasks_.emplace(task);
        }
        condition_variable_.notify_one();
        // condition_variable_.notify_all();
    }

    ~ThreadPool() {
        {
            {
                std::lock_guard<std::mutex> lock(mutex_);
                ended_= true;
            }
            condition_variable_.notify_all();

            for (auto& t : threads_)
            {
                t.join();
            }
        }
    }
};

void task(int index)
// void task()
{
    // int index = 0;
    std::cout << "Executing task " << index << " in thread " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

std::atomic<int> critical_section = 0;
std::mutex mx;
void race_task()
{
    // critical_section++;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    {
        // std::lock_guard<std::mutex> lock(mx);
        std::unique_lock<std::mutex> lock(mx);
        std::cout << "Executing task " << critical_section++ << " in thread " << std::this_thread::get_id() << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::seconds(1));
    return;
}

class Database
{
    int count_;
    mutable std::shared_mutex smutex_;

    public:
        Database(): count_(0){}

        int read() const
        {
            time_t start_time = time(NULL);
            std::cout << "Read starts at " << ctime(&start_time) << std::endl;
            std::shared_lock lock(smutex_);
            std::this_thread::sleep_for(std::chrono::seconds(1));
            time_t end_time = time(NULL);
            std::cout << "Read ends at " << ctime(&end_time) << std::endl;
            return count_;
        }

        int write()
        {   
            time_t start_time = time(NULL);
            std::cout << "Write starts at " << ctime(&start_time) << std::endl;
            std::unique_lock lock(smutex_);
            std::this_thread::sleep_for(std::chrono::seconds(3));
            time_t end_time = time(NULL);
            std::cout << "Write ends at " << ctime(&end_time) << std::endl;
            return ++count_;
        }
};

int main() {

    Database data;

    time_t my_time = time(NULL);
    std::cout << "Start at " << ctime(&my_time) << std::endl;

    std::thread t0 = std::thread([&]{std::cout << "Write value  " << data.write() << std::endl;});
    std::thread t1 = std::thread([&]{std::cout << "Read value " << data.read() << std::endl;});
    std::thread t2 = std::thread([&]{std::cout << "Write value  " << data.write() << std::endl;});
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::thread t3 = std::thread([&]{std::cout << "Read value " << data.read() << std::endl;});
    std::thread t4 = std::thread([&]{std::cout << "Read value " << data.read() << std::endl;});

    t0.join();
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    // ThreadPool pool(4);
    // for (int i = 0; i < 8; ++i) {
    //     pool.enqueue(task, i);
    //     // pool.enqueue(task);
    // }

    // std::vector<std::thread> threads;
    // for (int i = 0; i < 118; ++i) {
    //     threads.emplace_back(race_task);
    // }

    // for (auto& t : threads)
    // {
    //     t.join();
    // }



    return 0;
}