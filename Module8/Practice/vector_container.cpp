//
// Created by AbhishekJalkhare on 19-03-2026.
//
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main(int argc, char* argv[]) {

    vector<int>vec(5 , 0);
    vec[8] = 0;
    cout<<vec[7]<<endl; // garbage
    cout<<vec.size()<<endl; // size of vector still remains 5;

    vec.resize(50 , -1); // set new size of vector to 50
    // put x as their value;
    for (const auto& i : vec) cout<<i<<" ";
    cout<<endl;
    vec.resize(100 ); // sets to default value for int -> 0 to new elements
    for (const auto& i : vec) cout<<i<<" ";
    cout<<endl;

    vec.resize(5,0); // if new_size < current size destroys old element
    for (const auto& i : vec) cout<<i<<" ";
    cout<<endl;


    cout<<"capacity before reserve : "<<vec.capacity()<<endl;
    vec.reserve(5); // if n < current capacity no reallocation happens
    for (const auto& i : vec) cout<<i<<" ";
    cout<<"Capacity after reserve : "<<vec.capacity()<<endl;




}


