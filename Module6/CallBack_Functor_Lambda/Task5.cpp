//
// Created by AbhishekJalkhare on 05-03-2026.
//
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Add {
    int operator()(const int& x , const int& y) const {
        return x + y;
    }
};

int main(int argc, char* argv[]) {
    Add add;
    int result = add(10, 20); // or: Add{}(10, 20)

    std::cout << "Sum: " << result << std::endl;
    return 0;
}
