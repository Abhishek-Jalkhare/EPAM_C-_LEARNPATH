//
// Created by AbhishekJalkhare on 25-02-2026.
//
#include <iostream>
using namespace std;

template<typename T>
T add(T a, T b) {
    return a + b;
}

int main(int argc, char* argv[]) {
    int i = add(2, 3);          // int
    double d = add(2.1, 3.9);   // double
    float f = add(1.5f, 2.5f);  // float

    std::cout << "int: " << i << std::endl;
    std::cout << "double: " << d << std::endl;
    std::cout << "float: " << f << std::endl;
}
