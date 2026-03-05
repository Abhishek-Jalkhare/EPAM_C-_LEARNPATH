//
// Created by AbhishekJalkhare on 05-03-2026.
//

#include <iostream>
#include <functional>

auto makeLambda() {
    int temp = 5;
    // BAD: capturing local by reference!
    return [&temp]() { return temp * 2; }; // Lambda holds a reference to a local
}

int main() {
    auto lambda = makeLambda();
    std::cout << "Calling lambda after temp is gone: " << lambda() << std::endl; // Undefined behavior!
    return 0;
}
