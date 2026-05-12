//
// Created by AbhishekJalkhare on 07-05-2026.
//

#include<iostream>

namespace {
    int a  = 23;
    int add(int a , int b) {
        return a + b;
    }

}

namespace A ::B {
    int a  = 23;
    int add(int a , int b) {
        return a + b;
    }

}

namespace s = A::B;

int main(int argc, char *argv[]) {
    s::add(1,2);

}
