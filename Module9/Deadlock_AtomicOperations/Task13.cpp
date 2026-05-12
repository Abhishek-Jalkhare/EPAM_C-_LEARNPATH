//
// Created by AbhishekJalkhare on 20-04-2026.
//
#include <iostream>
#include <semaphore>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    std::counting_semaphore<2> sem(2); // Initialize with 2 permits

    auto fun = [&sem](int id) {
        sem.acquire(); // Acquire a permit
        cout << "Thread " << id << " has entered the critical section." << endl;
        this_thread::sleep_for(chrono::seconds(2)); // Simulate work
        cout << "Thread " << id << " is leaving the critical section." << endl;
        sem.release(); // Release the permit
    };

    thread t1(fun, 1);
    thread t2(fun, 2);
    thread t3(fun, 3);
    thread t4(fun, 4);
    thread t5(fun, 5);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
}
