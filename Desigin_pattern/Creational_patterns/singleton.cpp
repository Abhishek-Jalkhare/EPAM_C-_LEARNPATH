//
// Created by AbhishekJalkhare on 14-05-2026.
//

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class singleton {
    inline static once_flag flag;
    inline static unique_ptr<singleton> ptr = nullptr;
    singleton() {
        cout<<"Constructor"<<endl;
    }

    singleton(singleton&& s) = delete;
    singleton(const singleton& s) = delete;
    singleton& operator=(singleton&& s) = delete;
    singleton& operator=(const singleton& s) = delete;

public:
    static singleton& getInstance() {
        call_once(flag,[]() {
            ptr = unique_ptr<singleton>(new singleton());
        });

        return *ptr;
    }
};

int main(int argc, char *argv[]) {
    singleton& s1 = singleton::getInstance();
    singleton& s2 = singleton::getInstance();
    singleton& s3 = singleton::getInstance();
}
