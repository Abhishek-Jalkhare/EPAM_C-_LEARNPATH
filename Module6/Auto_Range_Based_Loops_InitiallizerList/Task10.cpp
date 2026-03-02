//
// Created by AbhishekJalkhare on 02-03-2026.
//
#include <iostream>
#include <vector>
using namespace std;

class Number {
    vector<int>v;
public:
    Number(initializer_list<int> init):v(init) {

    }

    void print() const{
        std::cout << "Numbers: ";
        for (auto x : v)
            std::cout << x << " ";
        std::cout << std::endl;
    }
};

int main() {
    Number nums{10, 20, 30, 40, 50};
    nums.print(); // Output: Numbers: 10 20 30 40 50
    return 0;
}
