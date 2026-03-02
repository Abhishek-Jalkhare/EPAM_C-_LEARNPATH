//
// Created by AbhishekJalkhare on 02-03-2026.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    std::vector<std::pair<int, std::string>> v{{1, "A"}, {2, "B"}};
    for (const auto& [num , str]:v) {
        std::cout << "num: " << num << ", str: " << str << std::endl;
    }
}
