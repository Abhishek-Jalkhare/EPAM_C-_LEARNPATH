//
// Created by AbhishekJalkhare on 27-01-2026.
//

#include<iostream>
using namespace std;

class Logger {
public:
    mutable int accessCount{}; // const function can change the value of mutable member
    string message{};

    void print() const { // const functions can not change the tate of object
        cout<<message << " value of access count : " << accessCount <<endl;
        accessCount++;
    }
};

int main(int argc, char *argv[]) {
    Logger l;
    l.message = "hello";
    l.print();
    l.print();
    l.print();
    l.print();

}
