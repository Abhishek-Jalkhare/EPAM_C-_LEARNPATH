//
// Created by AbhishekJalkhare on 01-04-2026.
//
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int cnt = 0;

// unsafe operation
// void fun() {
//     for (int i = 0 ; i < 1000000 ; i++) {
//         cnt++;  // critical section
//     }
// }


mutex mt;
void fun() {
    for (int i = 0 ; i < 10000000 ; i++) {
        // lock_guard<mutex>lg(mt);

        mt.lock();
        mt.lock();
        cnt++;
        mt.unlock();
        mt.unlock();
    }
}


int main(int argc, char* argv[]) {
    auto time1 = chrono::milliseconds(std::clock());
    // thread t1(fun);
    // thread t2(fun); // here thread unlock , lock 1 million tiimes this slows the solution
    //
    // t1.join();
    // t2.join();
    fun();
    fun();
    auto time2 = chrono::milliseconds(std::clock());
    cout<<time2-time1;
}
