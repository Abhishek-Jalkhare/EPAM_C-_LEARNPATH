//
// Created by AbhishekJalkhare on 14-04-2026.
//
#include <iostream>
#include <thread>
#include <bits/stdc++.h>
using namespace std;

mutex mtx;
condition_variable cv;
queue<int> buffer;
bool done = false;

void producer(int val) {
    int maxSize = val;
    while (val) {
        unique_lock<mutex> ul(mtx);
        cv.wait(ul , [maxSize](){return buffer.size() < maxSize;});
        cout<<"Produced : "<<val<<endl;
        buffer.push(val);
        val--;
        ul.unlock();
        cv.notify_one();
    }
    {
        lock_guard<mutex> lg (mtx); // this is required because cnsumer might read just at the momet w
        // e update done and  cause race condition
        done = true;
        cv.notify_one(); // need to notify after update r the thread may sleep forever
    }
}

void consumer() {
    while (true) {
        unique_lock<mutex> ul(mtx);
        cv.wait(ul , [](){return buffer.size() > 0  || done;});

        if (done && buffer.empty()) break;
        cout<<"Consumed : "<<buffer.front() << endl;
        buffer.pop();
        ul.unlock();
        cv.notify_one();
    }
}

int main(int argc, char *argv[]) {
    thread t1(consumer);
    thread t2(producer , 100);

    t1.join();
    t2.join();

}
