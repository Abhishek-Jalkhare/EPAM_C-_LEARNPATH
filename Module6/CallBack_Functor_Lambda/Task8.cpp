//
// Created by AbhishekJalkhare on 05-03-2026.
//
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    auto add = [](const int& a , const int& b ) {
        return a + b;
    };

    cout<<"Sum of 1 ,2  : "<<add(1,2);
}


