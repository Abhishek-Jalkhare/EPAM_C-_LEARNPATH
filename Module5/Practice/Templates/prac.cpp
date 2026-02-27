//
// Created by AbhishekJalkhare on 26-02-2026.
//
#include<iostream>
using  namespace  std;
void func() {
    cout<<endl;
}
template<typename F ,typename...T>
void func(F t, T...x) {
    cout<<t;
    func(x...);
}

int main(int argc, char* argv[]) {
    func(2,2.3,"shbh",true);
}

