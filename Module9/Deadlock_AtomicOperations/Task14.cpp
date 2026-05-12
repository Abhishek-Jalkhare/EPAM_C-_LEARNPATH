//
// Created by AbhishekJalkhare on 20-04-2026.
//

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class ThreadPool {
    vector<thread> threads;
    queue<function<void()>> tasks;
    mutex mtx;
    condition_variable cv;
    bool stop;

public:
    explicit ThreadPool(const size_t n) :stop{false}{
        for (size_t i = 0 ; i < n ; i++) {
            threads.emplace_back([this]() {
                while (true) {
                    function<void()> task;
                    unique_lock<mutex> ul(mtx);
                    cv.wait(ul ,[this]() {
                        return stop || !tasks.empty();
                    });
                    if (stop && tasks.empty()) break;
                    task = std::move(tasks.front());
                    tasks.pop();
                    task();
                }
            });
        }
    }

    void submit(const function<void()>& fn) {
        {
            lock_guard<mutex> lg(mtx);
            tasks.push(fn);
        }
        cv.notify_one(); // if sleeping thread this wakes it up
    }

    ~ThreadPool() {
        {
            lock_guard<mutex> lg(mtx); // this to prevent lost wakeup
            stop = true;
        }
        cv.notify_all();
        for (auto& t : threads) t.join();
    }

};

int main(int argc, char *argv[]) {
    ThreadPool pool(4); // Create a pool with 4 threads

    for (int i = 0; i < 8; ++i) {
        pool.submit([i] {
            std::cout << "Task " << i << " executing on thread "
                      << std::this_thread::get_id() << "\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        });
    }

}
