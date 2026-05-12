//
// Created by AbhishekJalkhare on 14-04-2026.
//

#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

using namespace std;

mutex mt1;
mutex mt2;

void fun1() {
    cout << "[Thread 1] Trying to lock mt1..." << endl;
    lock_guard<mutex> lg1(mt1);
    cout << "[Thread 1] Locked mt1! Sleeping for 1 sec..." << endl;

    this_thread::sleep_for(chrono::milliseconds(1000));

    cout << "[Thread 1] Woke up. Trying to lock mt2..." << endl; // WILL HANG HERE
    lock_guard<mutex> lg2(mt2);
    cout << "[Thread 1] Locked mt2! (You will never see this)" << endl;
}

void fun2() {
    cout << "[Thread 2] Trying to lock mt2..." << endl;
    lock_guard<mutex> lg1(mt2);
    cout << "[Thread 2] Locked mt2! Sleeping for 1 sec..." << endl;

    this_thread::sleep_for(chrono::milliseconds(1000));

    cout << "[Thread 2] Woke up. Trying to lock mt1..." << endl; // WILL HANG HERE
    lock_guard<mutex> lg2(mt1);
    cout << "[Thread 2] Locked mt1! (You will never see this)" << endl;
}

int main(int argc, char *argv[]) {
    thread t1(fun1);
    thread t2(fun2);
    t1.join();
    t2.join();

    cout << "This statement will be printed if no deadlock" << endl;
    return 0;
}