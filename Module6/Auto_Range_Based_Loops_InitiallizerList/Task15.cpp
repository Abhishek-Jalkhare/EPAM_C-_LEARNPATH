//
// Created by AbhishekJalkhare on 02-03-2026.
//
#include <vector>

#include <iostream>
using namespace std;

class Matrix {
    vector<vector<int>>v;
public:
    Matrix(initializer_list<initializer_list<int>>li) {
        for (const auto& i : li) {
            v.emplace_back(i);
        }
    }

    void printAndDouble() {
        std::cout << "Matrix elements:" << std::endl;
        for (auto& i : v) {
            for (auto& j : i) {
                cout<<j<<" ";
                j = j*2;
            }
            cout<<endl;
        }
    }

    void print()const {
        for (const auto& i : v) {
            for (const auto& j : i) {
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }


};

int main() {
    Matrix mat{
            {1, 2},
            {3, 4}
    };

    mat.printAndDouble();
    std::cout << "After doubling:" << std::endl;
    mat.print();
    // cout<<(cout<<"aa",1)<<endl;

    return 0;
}
