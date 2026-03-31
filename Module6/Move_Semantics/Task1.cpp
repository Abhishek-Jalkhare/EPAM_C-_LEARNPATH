//
// Created by AbhishekJalkhare on 09-03-2026.
#include <iostream>
#include <cstring>
using namespace std;

class MyString {
    char* data;
public:
    explicit MyString(const char* arr)  {
        data = new char[strlen(arr)+1];
        strcpy(data,arr);
    }

    MyString() {
        data = nullptr;
    }

    MyString(const MyString& other) {
        cout<<"copy\n";
        MyString(other.data);
    }

    MyString& operator=(const MyString& other) {
        if (this == &other ) return *this;
        cout<<"= assingment \n";
        delete[]this->data;
        data = new char[strlen(other.data)+1];;
        strcpy(data , other.data);
        return *this;
    }

    void print() const {
        // if we cout char* it will print charaters till it encounter null terminator
        // to print address we need to type cast it to void* type
       cout << "String: " << data << " (at: " << static_cast<const void*>(data) << ")\n";
    }

    ~MyString() {
        delete[] data;
    }
};

int main(int argc, char* argv[]) {
    const MyString s1("hello");
    const MyString s2 = s1; // copy constructor called
    MyString s3; // default constructor called
    s3 = s2; // copy assingment called

    s1.print();
    s2.print();
    s3.print();
    MyString m ();
    

}
