//
// Created by AbhishekJalkhare on 14-05-2026.
//

#include <iostream>
#include <tgmath.h>
#include <bits/stdc++.h>
using namespace std;

class mayers_singleton {
    mayers_singleton() {
        cout<<"constructor"<<endl;
    }
    mayers_singleton(const mayers_singleton& s1) = delete;
    mayers_singleton(mayers_singleton&& s1) = delete;
    mayers_singleton& operator=(const mayers_singleton& s1) = delete;
    mayers_singleton& operator=(mayers_singleton&& s1) = delete;

public:
    static mayers_singleton& getinstance() {
        static mayers_singleton obj;
        return obj;
    }
};


int main(int argc, char *argv[]) {
    mayers_singleton& s1 = mayers_singleton::getinstance();

}
