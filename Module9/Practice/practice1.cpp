//
// Created by AbhishekJalkhare on 31-03-2026.
//

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void fun() {
    for (int i = 0 ; i < 1000 ; i++) {
        cout<<i <<" ";
    }
    cout<<endl;
}

int main(int argc, char* argv[]) {
    thread t1(fun);
    this_thread::sleep_for(chrono::milliseconds(1));
    t1.detach();
    cout<<"Helloo";
}
