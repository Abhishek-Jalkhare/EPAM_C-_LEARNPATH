//
// Created by AbhishekJalkhare on 02-03-2026.
//

#include <iostream>
using namespace std;
template<typename... Args>
void sumAll(Args... args){
    int sum =0;
    ((cout<<(sum+=args)<<endl), ...);
}

int main() {
    sumAll(4,7,12);
    return 0;
}