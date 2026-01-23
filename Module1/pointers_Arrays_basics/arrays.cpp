#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int static_array[100] = {1,2}; // 1st  element is 1, 2nd element is 2, rest are 0
    cout<<"unexpected value for 100 index" <<static_array[100]<<endl;
    
    int* dynamic_array = new int[100]; // all elements uninitialized
    delete [] dynamic_array;
    cout<<"randomn garbage value"<<dynamic_array[0]<<endl;
    int* arr1 = new int[100](); // all elements initialized to 0
    int* arr2 = new int[100]{1,2}; // all elements initialized to 1,2 respectively rest to 0
    cout<<arr1[0]<<endl; // prints 1
    cout<<arr2[14]<<endl; // prints 2   
    cout<<arr2[0]<<endl; // prints 2   

    int * arr3 = new int[100]{}; // all elements initialized to 0
    cout<<arr3[99]<<endl; // prints 0
    int * arr4 = new int[3]{1,2,3}; // 
    return 0;
}
