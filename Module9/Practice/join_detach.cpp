//
// Created by AbhishekJalkhare on 13-04-2026.
//
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void fun() {
    for (int i = 0 ; i < 50000 ; i++){
        cout<<"hi "<<endl;
    }
}

int main(int argc, char *argv[]) {
    thread t(fun);
    this_thread::sleep_for(chrono::seconds(1));
    t.detach();
}
