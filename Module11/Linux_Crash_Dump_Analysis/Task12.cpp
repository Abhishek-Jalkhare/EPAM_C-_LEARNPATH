//
// Created by AbhishekJalkhare on 22-04-2026.
//
#include <iostream>
int main() {
    int* arr = new int[5];
    arr[6] = 123;             // Buffer overflow!
    delete[] arr;
    return 0;
}
