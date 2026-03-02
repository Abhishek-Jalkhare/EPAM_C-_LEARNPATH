//
// Created by AbhishekJalkhare on 02-03-2026.
//
#include <iostream>
using namespace std;


// template<typename T,typename  ...Args > if we write this function with recursive version then
// we get error print() already defined
// void print (T t,Args ... arg) {
//     cout<<"foldexpression : "<<t;
//    ( (cout<<" foldexpression : "<<arg) ,... );
// }

// template<typename ...Args> if we write this function then the recursive version will be called b
// because it is more speciallised as it try totake at least on input
// void print(Args ... arg) {
//     ( (cout<<" foldexpression : "<<arg) ,... );
// }

void print() {
    cout<<"end "<<endl;
}
template<typename T,typename ...Args>
void print(T t , Args ...args) {
    cout<<"recursive "<<t <<" ";
    print(args...);
}



int main(int argc, char* argv[]) {
    print(1,2,4);
    int arr []  = {3,1};
    int *ptr=arr; // it is of type int*  so when derefrence it gives int
    int (*a) [2] = &arr; // it points to whole array -> so when derefrence it gives int[2] and then again we
                    // derefrence that value

    int (&ref)[2] = arr; // ref is refrence to array os size 2
    cout<<*a[0]<<endl;
    cout<<ptr[0]<<endl;

}
