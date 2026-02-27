//
// Created by AbhishekJalkhare on 20-02-2026.
//

#include <iostream>
using namespace std;

void foo(int && x) {
    cout<<"R value int refrence"<<endl;
}

void foo(int & x) {
    cout<<"L value int refrence"<<endl;
}

template<typename ...Args>
void fun(Args && ...x) { // forwarding refrence can accept both lvalue and rvalue
    // foo(x...); // everytime l value will be called
    foo(forward<Args...>(x...) );
}


int main(int argc, char* argv[]) {
    fun(1);
    int x = 1;
    fun(x);
}
