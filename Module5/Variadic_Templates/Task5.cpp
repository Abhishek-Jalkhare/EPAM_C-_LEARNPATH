//
// Created by AbhishekJalkhare on 25-02-2026.
//
#include <iostream>
using namespace std;
void printAll() {
    cout<<endl;
}

template<typename T ,typename ...Args>
void printAll(T t , Args...args) {
    cout<<t;
    printAll(args...);
}

int main( ) {
    printAll(1,2,3,4,5,6);
    printAll(2,3,4,6,7,8);
}
