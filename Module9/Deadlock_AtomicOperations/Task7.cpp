//
// Created by AbhishekJalkhare on 14-04-2026.
//
#include <iostream>
#include <thread>
#include <atomic>
#include <vector>

// 1. Declare it atomic
std::atomic<int> counter{0};

void increment_safely() {
    for (int i = 0 ; i < 1000; i++) {
        // 2. Use relaxed memory order because we don't care about
        // synchronizing other variables, we just need the math to be atomic!
        counter.fetch_add(1);
    }
}

int main() {
    std::vector<std::thread> threads;
    for(int i = 0; i < 5; i++) {
        threads.emplace_back(increment_safely);
    }

    for(auto& t : threads) {
        t.join();
    }

    std::cout << "Final Value: " << counter.load() << "\n"; // Always 5000
    return 0;
}