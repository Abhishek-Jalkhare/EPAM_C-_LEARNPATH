//
// Created by AbhishekJalkhare on 20-02-2026.
//
#include <iostream>
using namespace std;
template<typename ...Args>
void fun(Args && ...x) { // forwarding refrence can accept both lvalue and rvalue
    cout<<"R Value"<<endl;
}
template<typename ...Args>
void fun(Args & ...x) {
    cout<<"L value"<<endl;
}

// template<typename ...Args>
// void wrapper( Args && ...arg ) {
//     foo(arg...);
// }


int main(int argc, char* argv[]) {
    fun(19);
    int x = 12;
    // fun(x); this will cause ambiguity because we have fun(T & x) which will take r value
    // and fun(T && x) which can take both r value and lvalue


}
