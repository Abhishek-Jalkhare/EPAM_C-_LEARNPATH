//
// Created by AbhishekJalkhare on 22-04-2026.
//
// buffer_overflow.cpp
#include <iostream>
int main() {
    int arr[5];
    arr[10] = 100; // Write out-of-bounds!
    std::cout << "Wrote past array bounds!" << std::endl;
    return 0;
}
// Compile with Debug Info & AddressSanitizer
//
// g++ -g -fsanitize=address -o buffer_overflow buffer_overflow.cpp
// ./buffer_overflow
//
