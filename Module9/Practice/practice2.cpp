//
// Created by AbhishekJalkhare on 31-03-2026.
//

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void fun() {

}

int main(int argc, char* argv[]) {
    thread t1(fun);

    this_thread::sleep_for(chrono::seconds(1));

    cout<<"wait over"<<endl;
    t1.join();
}
