//
// Created by AbhishekJalkhare on 03-02-2026.
//
#include<iostream>
using namespace std;

class Messenger {
public:
     void send(const string& msg ,  int priority)  {
        cout<<"Message Content : "<<msg << " with priority : "<<priority<<endl;
    }

    void send(const string& msg) {
        cout<<"Message Content : "<<msg << " with no priority "<<endl;
    }

};




int main(int argc, char* argv[]) {
    Messenger m;
    m.send("genric msg"); // single parameter definition of send is called
    m.send("genric msg" , 2); // 2 parameter send definition is called
}
