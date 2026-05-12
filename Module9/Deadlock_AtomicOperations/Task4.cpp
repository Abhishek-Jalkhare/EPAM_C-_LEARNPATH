//
// Created by AbhishekJalkhare on 14-04-2026.
//

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int counter = 0;

void increment() {
    for (int i = 0 ; i < 1000; i++) {
        counter++;
    }
}

int main(int argc, char *argv[]) {
    thread t1(increment);
    thread t2(increment);
    thread t3(increment);
    thread t4(increment);
    thread t5(increment);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    cout<<"Final Value : "<< counter<<endl;
}
