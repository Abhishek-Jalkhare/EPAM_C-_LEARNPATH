#include<iostream>
using namespace std;
void updateX(int* , int);

int main(int argc, char const *argv[])
{
    // declaration 
    // we need to provide type because cpu should know how many bytes to read

    int * p = new int (10);
    int * q , r ; // here r is not a pointer but a normal integer variable but q is a pointer
    q = new int (20);
    r = 30;

    // Operators * and & * dereference operator -> value at address , 
    // & address of operator -> address of variable    

    cout<<"Value at pointer p: "<<*p<<endl;
    cout<<"Address of r integer: "<<&r<<endl;
    delete p; // free the allocated memory
    delete q;
    // dynamic memory allocation -> use new() for single object , new[] for array of objects
    //use delete for single object , delete[] for array of objects
    

                                // POINTER ARITHMETIC
    int * arr = new int [5]{1,2,3,4,5};
    cout<<"Array elements using pointer arithmetic: "<<endl;

    for(int *i = arr ; i < arr + 5 ; i++){ // here i + 1 = i + sizeof(int)
        cout<<"Value at address "<<i<<" is "<<*i<<endl;
    }
    delete[] arr; // free the allocated memory for array  
    int a = 12;
    updateX(&a, 25);
    cout<<"updating value of a using pointer function value of a now : "<<a<<endl;
    return 0;
}


// pointers and functions

// 1 passing pointers to function

void updateX(int* x , int n){
     *x = n;
}


// 2 returning pointers from functions

// int* genrateTen(){
//     int x = 10;
//     return &x; // returning address of local variable is dangerous as it will go out of scope
//     // dangling pointer
// }

int* genrateTen(){
    
    return new int (10);  // caller must call delete
}

