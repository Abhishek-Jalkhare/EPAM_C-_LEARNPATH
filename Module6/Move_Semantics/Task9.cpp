//
// Created by AbhishekJalkhare on 11-03-2026.
//

#include <iostream>
#include <cstring>
using namespace std;

class MyString {
    char* data;
public:
    explicit MyString(const char* data) {
        cout<<"Parametrized constructor called"<<endl;
        this->data = new char[strlen(data) + 1];
        strcpy(this->data ,data);
    }

    MyString(const MyString& other) {
        cout<<"Copy Constructor called"<<endl;
        if (other.data == nullptr) {
            this->data = nullptr;
            return;
        }
        data = new char[strlen(other.data)+1];
        strcpy(this->data , other.data);
    }

    MyString(MyString&& other) noexcept{
        cout<<"Move Constructor called"<<endl;
        this->data = other.data;
        other.data = nullptr;
    }

    ~MyString() {
        cout<<"Destructor called"<<endl;
        delete [] data;
    }
};

MyString makeString() {
    MyString temp{"Hello"};
    //return MyString("hell0"); // RVO is gurannted for R value returns in c++17
    // return move(temp); this diable rvo
    return temp; // NRVO (this is not guranteed but mot compiler does it)
}

int main(int argc, char* argv[]) {
    MyString s = makeString(); // defaultly RVO is on so only parametrised constructor runs
    // and no move or copy happens 1 object created and one destructor runs

    //when we compile using g++  -fno-elide-constructors Task9.cpp the rvo is turned off
    // now make string calls parametrized constructor and return the temp object now since we
    // move semantics compiler will call move constructor now and since two objects are present
    // two destructor will run
}