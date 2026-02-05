//
// Created by AbhishekJalkhare on 03-02-2026.
//
#include <iostream>
using  namespace std;

class A {
public:
    A(int a) {
        cout<<"constructor created"<<endl;
    }
};

int main(int argc, char* argv[]) {
    void * ptr = operator new(sizeof(A)); // step 1 of new() is operator new to allocate meory which
    //retrun void type pointer
    A * a = new (ptr)A(1); // now we use placement new which calls constructor and typecast the void pointer
    int arr [5];
    cout<<sizeof(arr)/sizeof(int)<<endl;

}
