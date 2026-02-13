//
// Created by AbhishekJalkhare on 12-02-2026.
//
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    std::string name = "abhi";
    char arr[] = {'a','b','\0'};

    std:: string nm= std::string("abhi") + arr; // string class have a + opertor overload that allows
    // us to add a const char* arr;
    // "fxgfgg" whenever we write this this is a const char array
    std::cout<<nm;
    auto x=nm.c_str();
    auto y=nm.data();
    auto ptr=&nm[0];

}
