//
// Created by AbhishekJalkhare on 25-02-2026.
//
#include <iostream>
using namespace std;

template<typename T>
class Box {
    T value;
public:
    Box(T v) : value(v) {}
    void print() const {
        std::cout << value << std::endl;
    }
};
template<>
void Box<string>::print() const{
    string temp;
    for (char c : value) {
        cout<<static_cast<char>(toupper(c));
    }
    cout<<endl;
}

int main() {
    Box<std::string> boxStr("hello, Templates!");
    boxStr.print(); // Prints: HELLO, TEMPLATES!
    return 0;
}
