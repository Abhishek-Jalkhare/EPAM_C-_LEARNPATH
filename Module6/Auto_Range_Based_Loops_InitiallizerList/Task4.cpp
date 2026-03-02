//
// Created by AbhishekJalkhare on 02-03-2026.
//
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    vector<int> vec {1,2,3,4,5,6,7,5};
    // Use auto for iterator deduction
    for (auto i = vec.begin() ; i != vec.end() ; i++) {
        cout<<*i<<endl;
    }
}
