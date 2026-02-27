//
// Created by AbhishekJalkhare on 25-02-2026.
//
#include <iostream>
using namespace std;

template<typename T=int>
class Number {
    T value;
public:
    Number(T v):value(v){};
    void print() {
        std::cout<<"Type Name : "<<typeid(T).name() <<", Value : "<< value << std::endl;
    };
};

int main() {
    Number<> n1(100);           // Uses default type int
    Number<double> n2(3.14);    // Uses double

    n1.print();                 // Prints: 100
    n2.print();                 // Prints: 3.14

    return 0;
}

