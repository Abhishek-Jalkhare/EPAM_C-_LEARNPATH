//
// Created by AbhishekJalkhare on 08-05-2026cp

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class A {
    int a;
public:
    A(int n) :a(n) {
        cout<<"Parameterized constructor"<<endl;
    }

    A(A&& other) : A(move(other.a)){
        cout<<"Move constructor"<<endl;
    }


    A(A& other): A(other.a) {
        cout<<"copy constructor"<<endl;
    }

};

A fun(bool b) {
    A x(1);
    A y(2);

    if (b)
        return x;
    else
        return y;
}

auto fun() {
    A a(12);
    return a;
}

int main(int argc, char *argv[]) {
    A a = fun(true);
}

