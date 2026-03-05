//
// Created by AbhishekJalkhare on 05-03-2026.
//
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main(int argc, char* argv[]) {

        auto multiply = [](int x, int factor=2){ return x * factor; };

        std::cout << "multiply(10): " << multiply(10) << std::endl;      // Uses default factor 2
        std::cout << "multiply(10, 5): " << multiply(10, 5) << std::endl; // factor = 5

        return 0;


}
