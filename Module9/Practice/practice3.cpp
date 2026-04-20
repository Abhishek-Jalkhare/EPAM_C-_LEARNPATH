//
// Created by AbhishekJalkhare on 31-03-2026.
//


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class A {
public:
    A() {
        fun();
    }
   virtual void fun() {
        cout<<"Hello A"<<endl;
    }
};

class B : public virtual A{
    void fun() {
        cout<<"Hello B"<<endl;
    }
};

class C : public virtual A{
    void fun() {
        cout<<"Hello C"<<endl;
    }
};

class D : public B , public  C{
    void fun() {
        cout<<"Hello D"<<endl;
    }
};

int main(int argc, char* argv[]) {
    A * ptr = new B();
}
