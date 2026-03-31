//
// Created by AbhishekJalkhare on 13-03-2026.
//

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class IntArray {
    int* arr;
    size_t size;

public:
     explicit IntArray(const size_t size):arr(new int[size]) , size(size){
        std::cout << "Allocated array of size " << size << " at " << static_cast<void*>(arr) << std::endl;
        for (int i = 0 ; i < size ; i++) {
            arr[i] = 0;
        }
    }
    IntArray(const IntArray&) = delete;
    IntArray& operator=(const IntArray&) = delete;

    IntArray(IntArray&& other) noexcept
    : arr(other.arr), size(other.size)
    {
        other.arr = nullptr;
        other.size = 0;
    }

    IntArray& operator=(IntArray&& other) noexcept {
        if (this != &other) {
            delete[] arr;

            arr = other.arr;
            size = other.size;

            other.arr = nullptr;
            other.size = 0;
        }
        return *this;
    }

    int& operator[](const size_t i)  {
        if (i >= size)
            throw std::out_of_range(("index "+
                to_string(i) + " out of range for array of size "+
                to_string(size)).c_str());
        return arr[i];
    }

    const int& operator[](const size_t i) const {
        if (i >= size)
            __throw_out_of_range(("index "+
                to_string(i) + " out of range for array of size "+
                to_string(size)).c_str());
        return arr[i];
    }

    [[nodiscard]] size_t length() const{
         return this->size;
    }

    ~IntArray() {
        delete [] arr;
        cout<<"Destructor Called "<<endl;
    }
};

void testEarlyReturn() {
    IntArray a(5);
    a[0] = 42;
    std::cout << "testEarlyReturn: value[0] = " << a[0] << std::endl;
    return; // Destructor will be called automatically
}

void testException() {
    IntArray a(5);
    throw std::runtime_error("Oops! Exception triggered.");
}


int main(int argc, char* argv[]) {
    IntArray arr(5);
    arr[0] = 1;
    cout<<arr[0]<<endl;
    try {
        IntArray arr(3);
        std::cout << "Normal usage: value[1] = " << arr[1] << std::endl;
    } catch (...) { }

    std::cout << "-- Testing early return --\n";
    testEarlyReturn();

    try {
        std::cout << "-- Testing exception --\n";
        testException();
    } catch (const std::exception& ex) {
        std::cerr << "Caught exception: " << ex.what() << std::endl;
    }

    std::cout << "End of main reached.\n";

}

