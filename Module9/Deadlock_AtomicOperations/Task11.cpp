//
// Created by AbhishekJalkhare on 20-04-2026.
//
#include <iostream>
#include <mutex>
#include <condition_variable>
using namespace std;

bool ready = false;
mutex mtx;
condition_variable cv;

void waiter() {
    unique_lock<mutex> ul(mtx);
    cv.wait(ul , []() {
        return ready;
    });
    cout<<"Worker thread is proceeding after being signaled!"<<endl;
}

void signaler() {
    this_thread::sleep_for(chrono::seconds(2)); // Simulate some work
    {
        lock_guard<mutex> lg(mtx);
        ready = true;
        cout<<"Signaler thread is setting ready to true and notifying..."<<endl;
    }
    cv.notify_one();
}


int main(int argc, char *argv[]) {
    thread t1 (waiter);
    thread t2 (signaler);
    t1.join();
    t2.join();

}
