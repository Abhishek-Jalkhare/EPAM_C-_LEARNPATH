//
// Created by AbhishekJalkhare on 12-02-2026.
//
#include<bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char* argv[]) {
    std::string name = "abhi";
    char arr[] = {'a','b','\0'};
    int a = INT_MAX;
    std:: string nm= std::string("abhi") + arr; // string class have a + opertor overload that allows
    // us to add a const char* arr;
    // "fxgfgg" whenever we write is a const char array
   // std::cout<<nm;
    string s =name.substr(0,1);
    cout<<s;
    auto x=nm.c_str();
    auto y=nm.data();
    auto ptr=&nm[0];
    map<int, int> mp;
    mp[0] = 3;
    mp[1] = 4;
    mp[2] = 6;
    for (auto i : mp) {

    }

    priority_queue <int> pq;

}
