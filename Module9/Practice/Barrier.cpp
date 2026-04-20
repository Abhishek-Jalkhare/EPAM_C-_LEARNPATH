//
// Created by AbhishekJalkhare on 20-04-2026.
//
#include <iostream>
#include <barrier>
#include <bits/stdc++.h>
using namespace std;


int main(int argc, char *argv[]) {
    auto completion = []() {
        cout<<"All threads have reached the barrier!"<<endl;
    };
    barrier b(3 ,completion ); // 3 threads will wait on this barrier

    auto worker = [&b](int id) {
        cout<<"Thread "<<id<<" is doing some work..."<<endl;
        this_thread::sleep_for(chrono::seconds(1)); // Simulate work
        cout<<"Thread "<<id<<" is waiting at the barrier..."<<endl;
        b.arrive_and_wait(); // Wait for all threads to reach this point
        cout<<"Thread "<<id<<" has passed the barrier!"<<endl;
    };

    thread t1(worker , 1);
    thread t2(worker , 2);
    thread t3(worker , 3);

    t1.join();
    t2.join();
    t3.join();

}
