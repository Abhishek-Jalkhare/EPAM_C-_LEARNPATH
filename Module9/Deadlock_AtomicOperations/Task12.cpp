//
// Created by AbhishekJalkhare on 20-04-2026.
//
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    barrier b (3,[](){
        cout<<"All threads have reached the barrier. Continuing execution..."<<endl;
    });

    auto worker = [&b](int id) {
        cout<<"Thread "<<id<<" is doing some work..."<<endl;
        this_thread::sleep_for(chrono::milliseconds(1000 + id*500)); // Simulate work

        cout<<"Thread "<<id<<" has reached the barrier."<<endl;
        b.arrive_and_wait(); // Wait for all threads to reach the barrier
        cout<<"Thread "<<id<<" is past the barrier."<<endl;
    };

    thread t1(worker, 1);
    thread t2(worker, 2);
    thread t3(worker, 3);

    t1.join();
    t2.join();
    t3.join();

}
