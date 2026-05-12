//
// Created by AbhishekJalkhare on 02-04-2026.
//

#include <condition_variable>
#include <iostream>
#include <optional>

using namespace std;

optional<int> buffer;
mutex mtx;
condition_variable cv;
void producer() {
    for (int i = 1 ; i <= 10 ; i++) {
        unique_lock<mutex> ul(mtx);
        cv.wait(ul , []() {
            return !buffer.has_value();
        });
        buffer = i;
        cout<<"Produced "<<i <<endl;
        ul.unlock();
        cv.notify_one();
    }
}

void consumer() {
    for (int i = 0 ; i < 10 ; i++) {
        unique_lock<mutex> ul(mtx);
        cv.wait(ul ,[]() {
           return buffer.has_value();
        });
        cout<<" Consumed : "<<buffer.value()<<endl;
        buffer.reset();
        ul.unlock();
        cv.notify_one();
    }
}

int main(int argc, char* argv[]) {
    thread t1(producer);
    thread t2(consumer);
    t1.join();
    t2.join();

}
