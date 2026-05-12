//
// Created by AbhishekJalkhare on 01-04-2026.
//
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printMessage(const string& msg) {
    cout<<"Message : "<<msg <<", Thread_ID : "<<this_thread::get_id()<<endl;
}

int main(int argc, char* argv[]) {
    vector<thread> vec ;
    for (int i = 0 ; i < 10 ; i++) {
        vec.emplace_back(printMessage, "Msg from thread "+to_string(i+1));
    }

    for (auto& i : vec) {
        i.join();
    }
}
