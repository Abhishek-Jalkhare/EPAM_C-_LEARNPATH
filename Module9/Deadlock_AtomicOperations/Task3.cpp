//
// Created by AbhishekJalkhare on 14-04-2026.
//
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

mutex m1, m2, m3;
//
// void threadA() {
//     cout << "[Thread A] Trying to lock m1...\n";
//     lock_guard<mutex> lock1(m1);
//     cout << "[Thread A] Locked m1.\n";
//     this_thread::sleep_for(chrono::milliseconds(50)); // Yield to force overlap
//
//     cout << "[Thread A] Trying to lock m2...\n";
//     lock_guard<mutex> lock2(m2);
//     cout << "[Thread A] Locked m2.\n";
//     this_thread::sleep_for(chrono::milliseconds(50));
//
//     cout << "[Thread A] Trying to lock m3...\n";
//     lock_guard<mutex> lock3(m3);
//     cout << "[Thread A] Locked m3.\n";
//
//     cout << "[Thread A] Finished work!\n";
// }
//
// void threadB() {
//     cout << "[Thread B] Trying to lock m2...\n";
//     lock_guard<mutex> lock1(m2);
//     cout << "[Thread B] Locked m2.\n";
//     this_thread::sleep_for(chrono::milliseconds(50));
//
//     cout << "[Thread B] Trying to lock m3...\n";
//     lock_guard<mutex> lock2(m3);
//     cout << "[Thread B] Locked m3.\n";
//     this_thread::sleep_for(chrono::milliseconds(50));
//
//     cout << "[Thread B] Trying to lock m1...\n";
//     lock_guard<mutex> lock3(m1); // <-- DEADLOCK HAPPENS HERE
//     cout << "[Thread B] Locked m1.\n";
//
//     cout << "[Thread B] Finished work!\n";
// }
//
// void threadC() {
//     cout << "[Thread C] Trying to lock m3...\n";
//     lock_guard<mutex> lock1(m3);
//     cout << "[Thread C] Locked m3.\n";
//     this_thread::sleep_for(chrono::milliseconds(50));
//
//     cout << "[Thread C] Trying to lock m1...\n";
//     lock_guard<mutex> lock2(m1); // <-- DEADLOCK HAPPENS HERE
//     cout << "[Thread C] Locked m1.\n";
//     this_thread::sleep_for(chrono::milliseconds(50));
//
//     cout << "[Thread C] Trying to lock m2...\n";
//     lock_guard<mutex> lock3(m2);
//     cout << "[Thread C] Locked m2.\n";
//
//     cout << "[Thread C] Finished work!\n";
// }
// FIX
void threadA() {
    cout << "[Thread A] Requesting m1, m2, m3...\n";
    scoped_lock lock(m1, m2, m3);
    cout << "[Thread A] Acquired m1, m2, m3! Doing work...\n";

    this_thread::sleep_for(chrono::milliseconds(50));
    cout << "[Thread A] Finished work!\n";
}

void threadB() {
    cout << "[Thread B] Requesting m2, m3, m1...\n";
    // std::scoped_lock guarantees deadlock-free atomic acquisition,
    // regardless of the order they are passed in.
    scoped_lock lock(m2, m3, m1);
    cout << "[Thread B] Acquired m2, m3, m1! Doing work...\n";

    this_thread::sleep_for(chrono::milliseconds(50));
    cout << "[Thread B] Finished work!\n";
}

void threadC() {
    cout << "[Thread C] Requesting m3, m1, m2...\n";
    scoped_lock lock(m3, m1, m2);
    cout << "[Thread C] Acquired m3, m1, m2! Doing work...\n";

    this_thread::sleep_for(chrono::milliseconds(50));
    cout << "[Thread C] Finished work!\n";
}


int main() {
    cout << "Starting threads (Deadlock expected)...\n\n";
    thread t1(threadA);
    thread t2(threadB);
    thread t3(threadC);

    t1.join();
    t2.join();
    t3.join();

    cout << "Program completed successfully.\n";
    return 0;
}