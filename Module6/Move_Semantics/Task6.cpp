//
// Created by AbhishekJalkhare on 10-03-2026.
//
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Buffer {
    int* data;
    size_t size;
public:
    Buffer(const size_t size , const int data):size(size) {
        this->data = new int[size];
        for (int i = 0 ; i  < size ; i++) {
            this->data[i] = data;
        }
        std::cout << "Constructor called mem allocated at " << static_cast<void*>(this->data) << "\n";
    }

    Buffer(const Buffer& other): size(other.size) {
        this->data = new int[size];
        memcpy(this->data , other.data , size*sizeof(int));
        std::cout << "Copy ctor: copied to " << static_cast<void*>(data) << "\n";
    }

    Buffer& operator= (const Buffer& other) {
        if (this == &other) return *this;
        delete[] this->data;
        size = other.size;
        this->data = new int[size];
        memcpy(this->data , other.data , size*sizeof(int));
        std::cout << "Copy assign: copied to " << static_cast<void*>(data) << "\n";
        return *this;
    }

    Buffer(Buffer && other) noexcept:size(other.size) {
        this->data = other.data;
        other.data = nullptr;
        other.size = 0;
        std::cout << "Move ctor: take " << static_cast<void*>(data) << "\n";
    }

    Buffer& operator=(Buffer && other) {
        std::cout << "Move assign: take " << static_cast<void*>(data) << "\n";
        if (&other == this) return *this;
        delete[] this->data;
        this->size= other.size;
        this->data = other.data;
        other.data = nullptr;
        other.size = 0;
        return *this;
    }

    void print(const char* label) const {
        std::cout << label << " data at " << static_cast<const void*>(data) << ": [ ";
        for (size_t i = 0; i < size; ++i) std::cout << data[i] << " ";
        std::cout << "]" << std::endl;
    }

    ~Buffer() {
        cout<<"Memory freeed for : "<<static_cast<void*>(data)<<endl;
        delete[] data;
        data = nullptr;
    }

};


int main(int argc, char* argv[]) {
    Buffer a(3,1);   // Regular
    Buffer b = a;  // Copy constructor
    Buffer c(2,2);
    c = a;         // Copy assignment

    Buffer d = std::move(a); // Move constructor
    Buffer e(1,3);
    e = std::move(c);        // Move assignment

    b.print("b");
    d.print("d");
    e.print("e");

}
