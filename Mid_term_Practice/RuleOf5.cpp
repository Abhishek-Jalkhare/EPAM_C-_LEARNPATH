//
// Created by AbhishekJalkhare on 07-05-2026.
//

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class A {
    int a;
public:
    explicit A(const int n):a(n){}
    explicit A( A& other ) : A(other.a){}
    A(A&& other): a(move(other.a)) {
    }

    A& operator=(const A& other) {
        if (this != &other) {
            this->a = other.a;
            other.a = 0;
        }
        return *this;
    }

    A&& operator=(const A&& other) {
        if (this != other) {
            a= move(other.a);
            other.a = 0;
        }
    }




};


int main(int argc, char *argv[]) {
}
