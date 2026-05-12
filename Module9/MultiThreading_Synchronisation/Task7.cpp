//
// Created by AbhishekJalkhare on 02-04-2026.
//
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <shared_mutex>
using namespace std;

queue<int> buffer;
mutex mtx;
condition_variable cv;

void producer() {
    for (int i = 1 ; i <= 20 ; i++) {
        unique_lock<mutex> ul (mtx);
        buffer.push(i);
        cout<<"Produced : "<<i<<endl;
        cv.notify_one();
    }
}

void consumer() {
    for (int i = 0 ; i <20 ;i++) {
        unique_lock<mutex> ul(mtx) ;
        cv.wait(ul , []() {
            return !buffer.empty();
        });
        cout<<"Consumed : "<< buffer.front()<<endl;
        buffer.pop();
    }
}

int main(int argc, char* argv[]) {
    thread t1 (consumer);
    thread t2 ( producer);

    t1.join();
    t2.join();
}
