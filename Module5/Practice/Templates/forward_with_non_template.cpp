//
// Created by AbhishekJalkhare on 20-02-2026.
//

// we can not use forward in non template types here we use move to convert l val parameter
// move takes universal refrence  (lvalue , rvalue) and convert it to rvalue


#include <iostream>
using namespace std;


void foo ( int& x ) {
    cout<<"L Value"<<endl;
}

void foo(int && x) {
    cout<<"R value"<<endl;
}

void wrapper(int&& x) {
    // foo((int&&)(x)); use casting  or use move
    foo(move(x));

}

void wrapper(int & x) {
    foo(x);
}

int main(int argc, char* argv[]) {
    wrapper(12);
    int x  =12;
    wrapper(x);
}

