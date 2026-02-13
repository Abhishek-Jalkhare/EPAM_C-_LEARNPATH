//
// Created by AbhishekJalkhare on 04-02-2026.
//

#include <iostream>
using namespace std;

class Base {
public:
    Base() {
        cout<<"Constructor"<<endl;
    }
    ~Base() {
        cout<<"Destructor"<<endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        cout<<"Derived constructor"<<endl;
    }

    ~Derived() {
        cout<<"Derived destructor"<<endl;
    }

};

int main(int argc, char* argv[]) {
    Derived d;

}
