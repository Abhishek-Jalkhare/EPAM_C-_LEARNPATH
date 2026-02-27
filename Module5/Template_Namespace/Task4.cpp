//
// Created by AbhishekJalkhare on 25-02-2026.
//
#include <iostream>
using namespace std;

template<typename T>
class Box {
    T value;

public:
    explicit Box(const T& value)
        : value(value) {
    }

    void print() {
        cout<<"Value of Box : "<<value<<endl;
    }
};

int main(int argc, char* argv[]) {
    Box<int> intBox(42);
    Box<std::string> strBox("Hello, Templates!");

    intBox.print();   // Prints: 42
    strBox.print();   // Prints: Hello, Templates!

    return 0;
}
