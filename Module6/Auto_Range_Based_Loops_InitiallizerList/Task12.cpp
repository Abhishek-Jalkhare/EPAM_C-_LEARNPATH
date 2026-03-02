//
// Created by AbhishekJalkhare on 02-03-2026.
//
#include <vector>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    vector<vector<int>>mat = {{1,2},{3,4}};
    std::cout << "Matrix elements:" << std::endl;

    for (const auto& i : mat) {
        for (const auto& j : i) {
            cout <<j<<" ";
        }
        cout<<endl;
    }
}
