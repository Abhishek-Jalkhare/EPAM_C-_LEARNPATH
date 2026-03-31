//
// Created by AbhishekJalkhare on 09-03-2026.
//
// g++ -std=c++98 -fno-elide-constructors cpp_98.cpp -o main
#include <iostream>
using namespace std;
struct A {
    int *data;
    A(){
        data = new int(5);
    }

    A(const A& other) {
        data=new int(*other.data);
        std::cout << "Copy" << std::endl;
    }

    A(A&& other) {
        data = other.data;
        other.data = nullptr;
        cout<<"MOve"<<endl;
    }
    void getdata() const {
        if (data)
            std::cout<<*data<<std::endl;
        else
            std::cout<<"0";

    }

};

A createStruct(A &str) {
    *(str.data)=7;
    return str;
}




int main() {

    A a;
    A b = createStruct(a);
    return 0;
}