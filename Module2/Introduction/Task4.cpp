//
// Created by AbhishekJalkhare on 27-01-2026.
//
#include <iostream>
using namespace  std;

class DynamicArray {
public:
    int * data {};
    int size ;
    DynamicArray(int size) {
        this->size = size;
        data = new int [this->size]{};
        cout<<"Memory Allocated"<<endl;
    }

    DynamicArray(const DynamicArray & other) {
        this->size = other.size;
        data = new int[size];
        for (int i = 0 ; i < size ; i++) {
            data[i] = other.data[i];
        }
    }

    ~DynamicArray() {
        delete[] data;
    }


};


int main(int argc, char *argv[]) {
    DynamicArray arr1{10} ;
    arr1.data[0] = 9;

    DynamicArray arr2 = arr1;
    cout<<arr2.data[0]<<endl;
    arr2.data[0] = -1;
    cout<<arr2.data[0]<<endl;
    cout<<arr1.data[0]<<endl;
}
