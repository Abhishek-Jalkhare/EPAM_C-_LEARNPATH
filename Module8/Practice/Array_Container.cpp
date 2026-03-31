//
// Created by AbhishekJalkhare on 19-03-2026.
//
#include<iostream>
#include <algorithm>
#include <array>
using namespace std;

int main(int argc, char* argv[]) {
    int n = 100;
    array<int , 100 > arr{1,2,3,4} ;
    array<int , 5>arr2{};
    for (const auto& i : arr) {
        cout<<i<<endl;
    }
    int s = arr.size(); // the size factor is not lost;
    sort(arr.begin() , arr.end());


}
