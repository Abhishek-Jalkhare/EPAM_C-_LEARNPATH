//
// Created by AbhishekJalkhare on 02-03-2026.
//
#include <iostream>
#include <vector>
#include <initializer_list>

class Numbers {
public:
    std::initializer_list<int> list;
    Numbers(std::initializer_list<int> ilist) : list(ilist) {}
};

int main() {
    Numbers nums{1, 2, 3, 4, 5};

    std::cout << "Numbers: ";
    for (auto x : nums.list) { // auto deduces as int
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
