//
// Created by AbhishekJalkhare on 02-03-2026.
//
#include <vector>
#include <iostream>
using namespace std;

auto getNumbers() {
    return vector<int>{1,2,3};
}

int main(int argc, char* argv[]) {

    auto nums = getNumbers();   // No need for vector<int> on the left

    std::cout << "Returned numbers: ";
    for (auto n : nums)
        std::cout << n << " ";
    std::cout << std::endl;

    return 0;


}
