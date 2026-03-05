//
// Created by AbhishekJalkhare on 05-03-2026.
//
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    vector<int>vec{1,2,3,4,5,6,7,8};
    int fac = 3;
    cout<<"Using Capture by value on the vector with factor 3 : "<<endl;
    for_each(vec.begin() , vec.end() , [fac](int& x) {
        x*=fac;
    });

    for_each(vec.begin() , vec.end() , [](const int& x) {
        cout<<x<<" ";
    });

    cout<<"Using Capture by refrence on the vector with factor 3 : "<<endl;
    for_each(vec.begin() , vec.end() , [&fac](int& x) {
        x*=fac;
    });

    for_each(vec.begin() , vec.end() , [](const int& x) {
        cout<<x<<" ";
    });

    fac = 4; // modifying fac so refrence will take this value but in copy old one is used


}
