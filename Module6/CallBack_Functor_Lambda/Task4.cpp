//
// Created by AbhishekJalkhare on 05-03-2026.
//
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct MultiplyBy {
    int factor;

    void operator()(int& x) const {
        x *= factor;
    }
};

void print(const int& i) {
    cout<<i<<" ";
}

int main(int argc, char* argv[]) {
    vector<int> vec {1,2,3,4,5};
    cout<<"Initial Vector : "<<endl;
    for_each(vec.begin() , vec.end() , print);
    for_each(vec.begin() , vec.end() , MultiplyBy{3});
    cout<<endl<<"Vector After Modification : "<<endl;
    for_each(vec.begin() , vec.end() , print);

    }


