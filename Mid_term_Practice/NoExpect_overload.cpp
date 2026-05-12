//
// Created by AbhishekJalkhare on 08-05-2026.
//
#include <iostream>
using namespace std;

class A {
    A(int n) { cout<<"a"; }

    A( int n ) noexcept{cout<<"b";};

};



int main(int argc, char *argv[]) {
    A(1);
}
