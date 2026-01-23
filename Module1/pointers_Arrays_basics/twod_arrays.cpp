#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int arr [3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    } 
    
    int n ;
    cin>>n;
    int ** matrix = new int*[n]();
    for(int i=0;i<n;i++){
        matrix[i] = new int[i+1]();
     //   cout<<"size of arr[" << i<< "] is" <<sizeof(matrix[i])/sizeof(int)<<endl; we can not 
     // use sizeof to get size of dynamically allocated array , sizeof(matrix[i]) will give size of pointer
     
    }    
    return 0;
}
