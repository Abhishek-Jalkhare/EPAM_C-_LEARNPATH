//
// Created by AbhishekJalkhare on 03-03-2026.
//
#include <iostream>
using namespace std;

void greetMorning(const std::string& name) {
    std::cout << "Good morning, " << name << "!" << std::endl;
}
void greetEvening(const std::string& name) {
    std::cout << "Good evening, " << name << "!" << std::endl;
}

void invokeCallback(void (*ptr)(const string& ) , const string& name) {
    ptr(name);
}

int main(int argc, char* argv[]) {
    invokeCallback(greetMorning, "Alice");
    invokeCallback(greetEvening, "Bob");
    return 0;
}
