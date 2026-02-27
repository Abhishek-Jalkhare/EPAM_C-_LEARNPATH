//
// Created by AbhishekJalkhare on 20-02-2026.
//
#include <iostream>
using namespace std;

void printAll() {
    cout<<endl;
}
template<typename T ,typename ...Args>
void printAll(T t ,Args ...arg) {
    cout<<t<<"  ";
    printAll(arg...);
}

template<typename T ,typename ...Args>
void printAll1(Args ...arg) {
    //((cout<<arg<<"  "),...); // expands into (cout<<1 ),(cout<<2) works
    // fold expression syntax :
    // (args op ... op init)
    // (init op ... op args)
    // (args op ...)
    // (... op args)
    (cout<< ...<<arg );
    cout<<endl;

}


int main(int argc, char* argv[]) {
    // printAll("a" ,1, "ad", "wdqd", 43 , 0.3);
    // cout<<1 , cout<<2; this is a valid syntax
}

