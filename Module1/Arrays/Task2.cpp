//
// Created by AbhishekJalkhare on 02-02-2026.
//
#include<iostream>
using namespace std;
int* reverseArray(int arr[], int n) {
    int* reversed = new int[n];
    for (int i = 0; i < n; i++) {
        reversed[i] = arr[n - i - 1];
    }
    return reversed;
}

int main(int argc, char const *argv[])
{
    cout<<"enter the size of array"<<endl;
    int n;
    cin>>n;
    int *arr = new int[n];
    cout<<"enter the elements of array"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int* reversed = reverseArray(arr, n);
    for(int i = 0 ; i < n ; i++){
        cout<<reversed[i]<<" ";
    }
    delete[] arr;
    delete[] reversed;
    return 0;
}


