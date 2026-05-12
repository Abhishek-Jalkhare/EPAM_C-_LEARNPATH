//
// Created by AbhishekJalkhare on 02-04-2026.
//

#include <condition_variable>
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
int counter = 0;
std::mutex mtx;
std::condition_variable cv;
const int MAX = 20;


void odd() {
    while (counter < MAX){
        unique_lock<mutex> ul(mtx);
        cv.wait(ul , []() {
            return counter%2 != 0;
        });
        cout<<counter<<endl;
        counter++;
        ul.unlock();
        cv.notify_one();
    }
}

void even() {
    while (counter < MAX){
        unique_lock<mutex> ul(mtx);
        cv.wait(ul , []() {
            return counter%2 == 0;
        });
        cout<<counter<<endl;
        counter++;
        ul.unlock();
        cv.notify_one();
    }
}


int main(int argc, char* argv[]) {
    thread t1 (odd);
    thread t2(even);
    t1.join();
    t2.join();
}
