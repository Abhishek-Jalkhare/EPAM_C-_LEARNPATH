//
// Created by AbhishekJalkhare on 12-03-2026.
//
#include <iostream>
#include <cstring>
#include <utility>

class MyString {
    char* data;
public:
    MyString(const char* str) {
        data = new char[std::strlen(str) + 1];
        std::strcpy(data, str);
    }
    MyString(const MyString& other) {
        data = new char[std::strlen(other.data) + 1];
        std::strcpy(data, other.data);
    }
    MyString(MyString&& other) noexcept : data(other.data) {
        other.data = nullptr;
    }
    MyString& operator=(const MyString& other) {
        if (&other == this) return *this;
        delete [] this->data;
        if (other.data) {
            this->data = new char[strlen(other.data)+1];
            strcpy(this->data , other.data);
        }
        else {
            this->data = nullptr;
        }

        return *this;
    }

    MyString& operator=(MyString&& other)noexcept {
        if (this == &other) return *this;
        delete[] this->data;
        this->data = other.data;
        other.data = nullptr;
        return *this;
    }
    ~MyString() {
        delete[] data;
    }
    void print(const char* label) const {
        std::cout << label << " [data@" << static_cast<const void*>(data)
                  << "] " << (data ? data : "null") << std::endl;
    }
    void safeReset(const char* str) {
        delete[] data;
        data = new char[std::strlen(str) + 1];
        std::strcpy(data, str);
    }
};


int main(int argc, char* argv[]) {
    MyString a("first");
    a.print("a (before move)");
    MyString b(std::move(a));
    b.print("b");
    a.print("a (after move)");

    a = MyString("reassigned");
    a.print("a(after reassingning) : ");
}
