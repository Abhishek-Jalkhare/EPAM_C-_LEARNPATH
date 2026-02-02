//
// Created by AbhishekJalkhare on 02-02-2026.
//
#include <iostream>
#include <algorithm>
using namespace std;

void printArray(int arr[], int n);
void inputArray(int arr[], int n);
int linearSearch(int arr[], int n, int target);
int binarySearch(int arr[], int n, int target);
void printResult(int index, int key);

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

    cout<<"Enter the key to be searched: ";
    int key;
    cin>>key;

    int res = linearSearch(arr, n, key);
    printResult(res, key);

    sort(arr , arr+n);

    res = binarySearch(arr, n, key);
    printResult(res, key);
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


int linearSearch(int arr[], int n, int target){
    for(int i=0;i<n;i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}


int binarySearch(int arr[], int n, int target){
    int s = 0;
    int e = n-1;
    while(s <= e){
        int mid = s + (e-s)/2;
        if(arr[mid] == target)
            return mid;
        else if(arr[mid] > target)
            e = mid - 1;
        else
            s = mid + 1;
    }

    return -1;
}

void printResult(int index, int key){
    if(index != -1){
        cout << "Element " << key << " found at index " << index << "." << endl;
    } else {
        cout << "Element " << key << " not found in the array." << endl;
    }
}