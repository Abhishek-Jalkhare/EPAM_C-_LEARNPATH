//
// Created by AbhishekJalkhare on 28-01-2026.
//

#include <iostream>
using  namespace  std;


int* allocate()
{
    return new int;
}

int main(int argc, char* argv[])
{
    int * ptr = allocate();
    *ptr =1;
    cout<<"value at ptr before delete "<<*ptr<<endl;
    delete ptr;
    cout<<"value at ptr after delete "<<*ptr<<endl;

    ptr = nullptr;
    cout<<"value at ptr after setting it to null"<<*ptr<<endl;



}
