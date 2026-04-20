//
// Created by AbhishekJalkhare on 15-04-2026.
// compile with c++ 20
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<typename T>
concept subscriptAble = requires (T t) {
    t[0];
};

template<subscriptAble T>
void func(T a) {
    a[0];
}

int main(int argc, char *argv[]) {
    func(1);
}
