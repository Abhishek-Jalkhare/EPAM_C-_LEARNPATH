//
// Created by AbhishekJalkhare on 07-05-2026.
//

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class A {
public:
    int memberfun() {
        std::cout<<"member"<<std::endl;
    }
};

int add(int a , int b) {
    return a + b;
}

class functor {
    int state;

public:
    functor(const int n):state(n) {

    }
    int operator() (int n) const{
        return n* state;
    }
};





int main(int argc, char *argv[]) {
    int (*ptr) (int , int) = add; // function pointer
    int (A:: *ptr2) () = &A::memberfun;
    const functor f(3);
    f(12);

    int x = 0;
    auto l = [x]() mutable {
        x++;
        cout<<x<<endl;
    };
    // l();
    // l();
    // cout<<x<<endl;

    std::function<void ()> fn = l;
    fn();

}
