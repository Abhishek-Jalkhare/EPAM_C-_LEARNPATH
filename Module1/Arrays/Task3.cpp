//
// Created by AbhishekJalkhare on 02-02-2026.
//
#include <iostream>
using namespace std;

void printArray(int arr[], int n);
void inputArray(int arr[], int n);
void sortArray(int arr[], int n);

int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    if(n <= 0){
        cout << "Invalid array size." << endl;
        return 1;
    }
    int *arr = new int[n];
    inputArray(arr, n);
    sortArray(arr, n);
    printArray(arr, n);
    delete[] arr;
    return 0;
}

void inputArray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<"Enter element " << i+1 << ": ";
        cin>>arr[i];
    }
}

void printArray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void sortArray(int arr [] , int n){
    for(int i = 0 ; i < n; i ++){
        bool swapped = false;
        for(int j =0 ; j < n-i-1 ; j++){
            if(arr[j] > arr[j+1]){

                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }
        if(!swapped){
            break;
        }
    }
}