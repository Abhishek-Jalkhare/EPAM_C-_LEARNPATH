//
// Created by AbhishekJalkhare on 23-02-2026.
//
#include <iostream>
using namespace std;

void process(string && s) {
    cout<<"string literal : "<<s<<endl;
}

void process (  const string& s){
    cout<<"const refrence : "<<s<<endl;
}

void process(int& a) {
    cout<<"L Value int reference : "<<a<<endl;
}
void process(int&& a) {
    cout<<"R Value int : "<<a<<endl;
}


template<typename  ...Args>
void forwardAll(Args&& ...args) { // for catching both l val and r val reference wee need to use
    //forwarding reference Args ...args is simply a pass by value

  (  process(forward<Args>(args)) ,...); // when we use forward on copy value it usually does this
                                        // (int&&)args so everything becomes R value
    // process(args...);
}

int main(int argc, char* argv[]) {
    int b = 9;
    string temp = "abc";
    forwardAll(temp, 1,2,3,"hellp",b);             // rvalue and expression

}
