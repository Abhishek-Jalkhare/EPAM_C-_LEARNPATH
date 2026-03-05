//
// Created by AbhishekJalkhare on 05-03-2026.
//

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    int counter = 0;
    auto next = [counter]()mutable {
        counter++;
        return counter;
    };

    cout<<"Calling Next : "<< next()<<endl;
    cout<<"Calling Next : "<< next()<<endl;
    cout<<"Calling Next : "<< next()<<endl;
    cout<<"Calling Next : "<< next()<<endl;
    cout<<"Calling Next : "<< next()<<endl;
    std::cout << "Outer counter: " << counter << std::endl; // 0




}
