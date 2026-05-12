//
// Created by AbhishekJalkhare on 11-05-2026.
//

#include <atomic>
#include <condition_variable>
#include<iostream>
#include <queue>
#include <mutex>
#include <thread>
#include <vector>
using namespace std;

queue<int>buffer;
size_t max_size = 10;
mutex mt1;
bool isReady = true;
bool done = false;
condition_variable cv;

void producer(int n) {
    while (n) {
        unique_lock<mutex> ul(mt1);
        cv.wait(ul , []() {
            return max_size != buffer.size();
        });
        int a = rand()%10;
        buffer.push(a);
        n--;
        cout<<"Produced : "<<a<<endl;
        ul.unlock();
        cv.notify_all();
    }

    {
        lock_guard<mutex> lg(mt1);
        done = true;
    }
    cv.notify_one();
}

void consumer() {
    while (true) {
        unique_lock<mutex> ul(mt1);
        cv.wait(ul , []() {
           return buffer.size() > 0 || done;
        });
        if (buffer.size() == 0 && done) return;
        cout<<"Consumed : "<<buffer.front()<<endl;
        buffer.pop();
        ul.unlock();
        cv.notify_one();
    }
}


int main(int argc, char *argv[]) {
    thread t1(consumer);
    thread t2(producer , 50000);
    atomic<int> a(12);

    t1.join();
    t2.join();
}
