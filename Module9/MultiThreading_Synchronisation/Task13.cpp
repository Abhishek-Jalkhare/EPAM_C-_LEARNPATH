//
// Created by AbhishekJalkhare on 09-04-2026.
//

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// reates two std::mutex objects
// Starts two threads which attempt to lock both mutexes,
// but in opposite order (to simulate deadlock)
// Demonstrates the deadlock by noting that both threads get stuck
// Fixes the code by replacing the locking with std::lock()
// (or std::scoped_lock in C++17), ensuring both mutexes are acquired atomically without deadlock

mutex mt1;
mutex mt2;
//
// void fun1() {
//     lock_guard<mutex>lg1(mt1);
//     this_thread::sleep_for(chrono::milliseconds(1000));
//     lock_guard<mutex>lg2(mt2);
// }
//
// void fun2() {
//     lock_guard<mutex>lg1(mt2);
//     this_thread::sleep_for(chrono::milliseconds(1000));
//     lock_guard<mutex>lg2(mt1);
// }

//these implementation would cause deadlock
//because they acquire lock in different order , and one thread is
//waiting for other to release its resources , so we uese std::lock() , std::scoped_lock()
// to acquire lock;


void fun1() {
    lock(mt1,mt2 );
    lock_guard<mutex> lg1(mt1 , adopt_lock);
    this_thread::sleep_for(chrono::milliseconds(100));
    lock_guard<mutex> lg2(mt2 , adopt_lock);
    this_thread::sleep_for(chrono::seconds(1)); // simulating work
}


void fun2() {
    lock(mt1,mt2 );
    lock_guard<mutex> lg2(mt2 , adopt_lock);
    this_thread::sleep_for(chrono::milliseconds(100));
    lock_guard<mutex> lg1(mt1 , adopt_lock);
    this_thread::sleep_for(chrono::seconds(1)); // simulating work
}

//scoped Lock Implementation
// void fun2() {
//     scoped_lock<mutex , mutex>(mt1, mt2);
// }


int main(int argc, char *argv[]) {
    thread t1(fun1);
    thread t2(fun2);
    t1.join();
    t2.join();

    cout<<"THis statement will be printed if no deadlock"<<endl;
}
