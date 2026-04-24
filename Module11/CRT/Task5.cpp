#include <iostream>
#include <cstring>
#ifdef _WIN32
#include <crtdbg.h>
#endif

class Person {
    char* name;
public:
    Person(const char* nm) {
        size_t len = std::strlen(nm) + 1;
        name = new char[len];
        std::strcpy(name, nm);
    }
    ~Person() {
        delete[] name; // Proper cleanup!
    }
    void greet() const {
        std::cout << "Hello, my name is " << name << std::endl;
    }
};
int main() {
#ifdef _WIN32
	//std::cout << "Windows detected, enabling CRT debug flags for leak detection." << std::endl; 
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
    Person p1("Alice");
    Person p2("Bob");
    p1.greet();
    p2.greet();
    return 0;
}
