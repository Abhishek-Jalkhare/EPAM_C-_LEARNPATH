//
// Created by AbhishekJalkhare on 02-03-2026.
//
#include <iostream>

#include <iostream>

int main() {
    int x = 10;
    int* ptr = &x;
    auto p = ptr;   // p is int*
    auto& r = x;    // r is int&

    // Modify via reference
    r = 20;
    // Modify via pointer
    *p = 30;

    // Print all three
    std::cout << "x = " << x << std::endl;
    std::cout << "*p = " << *p << std::endl;
    std::cout << "r = " << r << std::endl;

    return 0;
}
