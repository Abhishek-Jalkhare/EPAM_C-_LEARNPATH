//
// Created by AbhishekJalkhare on 04-02-2026.
//

#include <iostream>
using namespace std;

class Base {
public:
    virtual void fun() {
        cout<<"base fun"<<endl;
    }
    virtual ~Base() = default;
};

class Derived : public Base {
public:
    void fun() override {
        cout<<"Derived fun"<<endl;
    }

};

int main(int argc, char* argv[]) {
    Base * a = new Derived();
    a->fun();
    Base * b = new Base();
    b->fun();

    delete a;
    delete b;

}
