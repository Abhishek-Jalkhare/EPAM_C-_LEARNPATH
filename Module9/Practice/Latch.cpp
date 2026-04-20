//
// Created by AbhishekJalkhare on 20-04-2026.
#include <iostream>
#include <latch>
#include <thread>
#include <vector>

int main() {
    const int num_workers = 3;
    // Initialize latch with the number of expected signals
    std::latch work_done(num_workers);

    auto worker = [&](int id) {
        std::cout << "Worker " << id << " is doing initial setup...\n";
        // Simulate work...

        // Signal that this thread's portion is complete
        work_done.count_down();

        std::cout << "Worker " << id << " is doing independent secondary work...\n";
    };

    std::vector<std::jthread> threads;
    for (int i = 0; i < num_workers; ++i) {
        threads.emplace_back(worker, i);
    }

    // Main thread waits here until the latch hits 0
    work_done.wait();
    std::cout << "All workers finished setup. Main thread proceeding.\n";
}