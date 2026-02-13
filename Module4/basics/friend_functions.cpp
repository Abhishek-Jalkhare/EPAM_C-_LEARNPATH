//
// Created by AbhishekJalkhare on 10-02-2026.
//
#include <iostream>
using namespace std;

class A {
    int a=3,b=7;
public:

    A operator+(const A& bb) {
        A obj;
        obj.a = a +bb.a;
        obj.b=b+bb.b;
        return obj;
    }
    void get() {
        cout<<a<<" "<<b<<endl;
    }
};

int main(int argc, char* argv[]) {
    A a,b,c;
    c=a+b;
    c.get();
}
