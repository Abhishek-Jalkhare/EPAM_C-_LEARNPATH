//
// Created by AbhishekJalkhare on 14-04-2026.
//

#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

std::mutex mtx1, mtx2;

void backoff_worker() {
    while (true) {
        std::unique_lock<std::mutex> lock1(mtx1);

        // Try to get the second lock WITHOUT blocking
        if (mtx2.try_lock()) {
            std::unique_lock<std::mutex> lock2(mtx2, std::adopt_lock);
            std::cout << "Got both locks! Doing work.\n";
            return; // Work is done, locks release automatically
        }

        // If we failed to get mtx2, we must release mtx1 immediately
        // to let other threads progress, then wait and try again.
        lock1.unlock();
        std::this_thread::yield(); // Let other threads run
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}
