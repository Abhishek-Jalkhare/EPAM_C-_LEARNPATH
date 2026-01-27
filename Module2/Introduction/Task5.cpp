//
// Created by AbhishekJalkhare on 27-01-2026.
//

#include <iostream>
using namespace std;

class DynamicArray {
public:
    int * data {};
    int size ;
    DynamicArray(int size) {
        this->size = size;
        data = new int [this->size]{};
        cout<<"Memory Allocated With intial block memmory address : "<<data<<endl;
    }

    DynamicArray(const DynamicArray & other) {
        this->size = other.size;
        data = new int[size];
        for (int i = 0 ; i < size ; i++) {
            data[i] = other.data[i];
        }
    }

    ~DynamicArray() {
        cout<<"Object Destroyed With intial block memmory address : "<<data<<endl;
        delete[] data;
    }


};

void demoDestructors() {
    DynamicArray arr1 (5);
    DynamicArray arr2 (5);
    DynamicArray arr3 (5);
    DynamicArray arr4 (5);
    DynamicArray arr5 (5);
    DynamicArray arr6 (5);
    DynamicArray arr7 (5); // this object will be destroyed first
}

int main(int argc, char *argv[]) {
    demoDestructors();
}
