//
// Created by AbhishekJalkhare on 13-04-2026.
//
#include <iostream>
#include <future>
#include <thread>
#include <chrono>

void sleep_task() { std::this_thread::sleep_for(std::chrono::seconds(2)); }

int main() {
    // BUG / UNINTENDED BEHAVIOR:
    // The future is unassigned, so its destructor is called immediately.
    // This blocks the main thread for 2 seconds right here.
    std::async(std::launch::async, sleep_task);

    std::cout << "This prints AFTER 2 seconds.\n";

    // CORRECT USAGE: Assign to a variable.
    auto fut = std::async(std::launch::async, sleep_task);

    std::cout << "This prints IMMEDIATELY.\n";

    // 'fut's destructor will run at the end of the scope block.
    // It will block here at the closing brace if the task hasn't finished.
}