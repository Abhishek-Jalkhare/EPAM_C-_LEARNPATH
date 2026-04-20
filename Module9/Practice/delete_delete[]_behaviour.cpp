#include <iostream>
using namespace std ;


int main()
{
    int * arr = new int[3]();
    delete [] arr;
    arr = nullptr;
    delete [] arr;



    return 0;
}