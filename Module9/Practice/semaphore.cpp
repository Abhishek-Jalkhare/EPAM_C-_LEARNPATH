//
// Created by AbhishekJalkhare on 20-04-2026.
//
//
// Created by AbhishekJalkhare on 20-04-2026.
//
#include <iostream>
#include <thread>
#include <semaphore>
#include <chrono>

using namespace std;

// Initialize binary semaphore with 0 so the waiter blocks immediately
binary_semaphore smph(0);

void waiter() {
    smph.acquire(); // Blocks until the semaphore's count is increased
    cout << "Worker thread is proceeding after being signaled!" << endl;
}

void signaler() {
    this_thread::sleep_for(chrono::seconds(2)); // Simulate some work
    cout << "Signaler thread is notifying..." << endl;
    smph.release(); // Increments count to 1, waking up the waiter
}

int main(int argc, char *argv[]) {
    thread t1(waiter);
    thread t2(signaler);

    t1.join();
    t2.join();

    return 0;
}