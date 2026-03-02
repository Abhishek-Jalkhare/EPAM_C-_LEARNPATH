//
// Created by AbhishekJalkhare on 02-03-2026.
//

#include <iostream>
using namespace std;

int& funReturningRefrence() {
     static int x = 12;
        return x;
}

int main(int argc, char* argv[]) {

    auto x = funReturningRefrence();


    auto y = funReturningRefrence();

    std::cout << "x = " << x << " (address: " << &x << ")" << std::endl;
    std::cout << "y = " << y << " (address: " << &y << ")" << std::endl;

    y = 100; // modifies static int in function
    std::cout << "After y = 100, x = " << x << ", y = " << y << std::endl;

    return 0;
}
