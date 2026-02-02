//
// Created by AbhishekJalkhare on 02-02-2026.
#include<iostream>
using namespace std;

void inputArray(int arr[] , int n);
int sumArray(int arr[] , int n);
float calculateAverage(int arr[] , int n);

int main(int argc, char const *argv[])
{
    cout << "Enter size of array: ";
    int n;
    cin>>n;
    int * arr = new int[n];
    inputArray(arr, n);
    cout << "Sum of array elements: " << sumArray(arr, n) << endl;
    cout << "Average of array elements: " << calculateAverage(arr, n) << endl;
    delete[] arr;


    return 0;
}

void inputArray(int arr[] , int n){
    for(int i=0;i<n;i++){
        cout<<"Enter element " << i+1 << ": ";
        cin>>arr[i];
    }
}

int sumArray(int arr[] , int n){
    int sum =0;
    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    return sum;
}

float calculateAverage(int arr[] , int n){
    int sum = sumArray(arr, n);
    return (float)sum/n;
}
