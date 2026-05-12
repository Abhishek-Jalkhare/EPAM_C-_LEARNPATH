//
// Created by AbhishekJalkhare on 07-05-2026.
//

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<typename ...Args>
auto print(Args ...args) {
    (cout<<...<<args);
}

template<typename T>
auto fun(T t) {
    cout<<"h";
}

template<>
auto fun(int a) {
    cout<<"i";
}


int main(int argc, char *argv[]) {
    using ll = long long;
    typedef long long ll;
    fun<int>(1);
}
