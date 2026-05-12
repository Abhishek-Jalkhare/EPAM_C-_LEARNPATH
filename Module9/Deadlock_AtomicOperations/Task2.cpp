//
// Created by AbhishekJalkhare on 14-04-2026.
//

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
    lock(mt1, mt2);
    lock_guard<mutex> lg2(mt1 , std::adopt_lock);
    lock_guard<mutex> lg1(mt2 , std::adopt_lock);
}

// void fun2() {
//     lock(mt1, mt2);
//     lock_guard<mutex> lg1(mt2 , std::adopt_lock);
//     lock_guard<mutex> lg2(mt1 , std::adopt_lock);
//
// }

void fun2() {
    scoped_lock<mutex , mutex> sl(mt1, mt2);



}

int main(int argc, char *argv[]) {
    thread t1(fun1);
    thread t2(fun2);
    t1.join();
    t2.join();

    cout << "This statement will be printed if no deadlock" << endl;
    return 0;
}