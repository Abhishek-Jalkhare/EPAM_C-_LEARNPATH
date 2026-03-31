//
// Created by AbhishekJalkhare on 09-03-2026.
//
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void fun() {
    cout<<"a";
}

void fun2(int v) {
    cout<<"a";
}


int main(int argc, char* argv[]) {

    auto a = [](){};
    auto *b = fun2;
    cout << typeid(fun2).name() << " " << typeid(fun).name() << " " << typeid(a).name()<<" :"<<typeid(*b).name();
}
