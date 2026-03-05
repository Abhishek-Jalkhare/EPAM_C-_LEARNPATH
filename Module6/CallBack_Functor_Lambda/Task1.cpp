//
// Created by AbhishekJalkhare on 03-03-2026.
//
#include <iostream>
using namespace std;
namespace xyz {
    int a;
}
using namespace std;

void greet(const string& name) {
    std::cout << "Hello, " << name << "!" << std::endl;
}

void invokeCallback(void(*ptr)(const string& ) , const string& name) {
    ptr(name);// Call the function pointer
}

int main(int argc, char* argv[]) {
    invokeCallback(greet , "AJ");
}
