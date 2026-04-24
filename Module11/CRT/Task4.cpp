//
// Created by AbhishekJalkhare on 23-04-2026.
//
#include <iostream>
#include <string.h>

class Person {
    char* name;
public:
    Person(const char* nm) {
        size_t len = strlen(nm) + 1;
        name = new char[len];
        strcpy(name, nm);
    }
    // No destructor OR destructor without 'delete[] name' (intentional leak)
    ~Person() { /* missing delete[] name; */ }
    void greet() const {
        std::cout << "Hello, my name is " << name << std::endl;
    }
};

#ifdef _WIN32
#include <crtdbg.h>
#endif

int main() {
#ifdef _WIN32
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
    Person p1("Alice");
    Person p2("Bob");
    p1.greet();
    p2.greet();
    return 0; // 'name' buffers are leaked!
}
