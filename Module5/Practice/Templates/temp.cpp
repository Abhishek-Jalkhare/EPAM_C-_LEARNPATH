//
// Created by AbhishekJalkhare on 19-02-2026.
//

#include <iostream>
#include <stdexcept>
using namespace std;

void A() {
    throw std::runtime_error("A");
}

void B() {
    try {
        A();
    }catch (const exception& e) {
        cout<<"A pakada gaya : "<<e.what()<<endl;
        throw ;
    }
}

void C() {
    try {
        B();
    }
    catch (const exception& e) {
        cout<<"B pakda : "<<e.what()<<endl;
        throw ;
    }
}


int main(int argc, char* argv[]) {
    try {
        C();
    }catch (const exception& e) {
        cout<<e.what();
        // throw ;
    }
}
