//
// Created by AbhishekJalkhare on 23-02-2026.
//
#include <iostream>
using namespace std;

template<typename ... Args>
auto sumAll(Args ...args) {
    return ( ... + args); // fold expression with init value zero
}

// Variadic recursive approach more code
int sumAll1() { return 0; }

template<typename T, typename... Args>
auto sumAll1(T first, Args... args) {
    return first + sumAll1(args...);
}

int main(int argc, char* argv[]) {
    int arr[] = {1,2};
    int arr2[] = {1,2};
    arr2 = arr;
    cout<<sumAll(1,1,2,1,5,4,23,5,45,6.54,3,2.43);
}
