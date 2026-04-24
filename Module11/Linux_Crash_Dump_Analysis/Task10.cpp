//
// Created by AbhishekJalkhare on 22-04-2026.
//
#include <iostream>
int main() {
    int* ptr;     // UNINITIALIZED pointer
    *ptr = 10;    // Dereference triggers undefined behavior/crash
    std::cout << *ptr << std::endl;
    return 0;
}