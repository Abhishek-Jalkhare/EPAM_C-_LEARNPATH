//
// Created by AbhishekJalkhare on 14-04-2026.
//
#include <iostream>
#include <thread>
#include <atomic>
#include <vector>

using namespace std;

// SCENARIO 1: The 'volatile' variable
volatile int volatile_counter = 0;

// SCENARIO 2: The 'std::atomic' variable
std::atomic<int> atomic_counter{0};

void increment_volatile() {
    for (int i = 0; i < 10000; ++i) {
        // This looks like one step, but it is actually three:
        // 1. Read from memory, 2. Add 1, 3. Write to memory.
        volatile_counter++;
    }
}

void increment_atomic() {
    for (int i = 0; i < 10000; ++i) {
        // This is guaranteed to be a single, indivisible hardware instruction.
        atomic_counter++;
    }
}

int main() {
    const int num_threads = 5;

    cout << "--- SCENARIO 1: volatile int ---\n";
    cout << "Expected Value: 50000\n";

    vector<thread> v_threads;
    for (int i = 0; i < num_threads; ++i) {
        v_threads.emplace_back(increment_volatile);
    }
    for (auto& t : v_threads) {
        t.join();
    }

    cout << "Actual Value  : " << volatile_counter
         << "  <-- (Massive data loss due to race conditions!)\n\n";

    // ---------------------------------------------------------

    cout << "--- SCENARIO 2: std::atomic<int> ---\n";
    cout << "Expected Value: 50000\n";

    vector<thread> a_threads;
    for (int i = 0; i < num_threads; ++i) {
        a_threads.emplace_back(increment_atomic);
    }
    for (auto& t : a_threads) {
        t.join();
    }

    cout << "Actual Value  : " << atomic_counter.load()
         << "  <-- (Perfectly synchronized!)\n";

    return 0;
}