//
// Created by AbhishekJalkhare on 05-03-2026.
//
#include <iostream>
#include <functional>
using namespace std;


void invokeCallback(std::function<void(const std::string&)> callback, const std::string& name) {
    callback(name);
}


int main(int argc, char* argv[]) {
    int y = 10;
    invokeCallback([y](const string& x) {
        cout<<"Lambda says hi to " << x << "!" << endl;
        cout<<"Captured Varable : "<<y<<endl;
    },"Bob");
}