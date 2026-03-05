//
// Created by AbhishekJalkhare on 05-03-2026.
//
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print(const int& i) {
    cout<<i<<" ";
}

int main(int argc, char* argv[]) {
    vector<int>vec{1,2,3,4,5,6,7,8};
    cout<<"vector before modification"<<endl;
    for_each(vec.begin() , vec.end() , print);
    for_each(vec.begin(), vec.end(),[](int& x) {
        x*= 2;
    });
    cout<<"vector after modification : "<<endl;
    for_each(vec.begin() , vec.end() , print);

}
