//
// Created by AbhishekJalkhare on 09-03-2026.
//
//
// Created by AbhishekJalkhare on 09-03-2026.
//
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
        cout<<"copy constructor called \n";
        if (other.data) {
            data = new char[strlen(other.data)+1];
            strcpy(data , other.data);
        }
        else {
            this->data = nullptr;
        }

    }

    MyString(MyString&& other)noexcept :data(other.data) {
        cout<<"Move constructor called \n";
        other.data = nullptr;
    }

    MyString& operator=(const MyString& other) {
        if (other.data == nullptr) {
            delete[]this->data;
            data = nullptr;
            return *this;
        }
        if (this == &other ) return *this;
        cout<<"copy assingment called\n";
        delete[]this->data;
        data = new char[strlen(other.data)+1];;
        strcpy(data , other.data);
        return *this;
    }

    ~MyString() {
        delete[] data;
    }

    MyString& operator=(MyString&& other)  noexcept {
        if (&other == this)return *this;
        delete [] data; // free previous resources
        this->data = other.data;
        other.data = nullptr;
        return *this;
    }



    void print(const char* label) const {
        std::cout << label << "String: ";
        if (data)
            std::cout << data;
        else
            std::cout << "(null)";
        std::cout << " (at: " << static_cast<const void*>(data) << ")\n";
    }
};

int main(int argc, char* argv[]) {
    cout << "\n--- Move Constructor ---\n";
    MyString s1("hello");
    s1.print("s1 before move: ");
    MyString s2 = std::move(s1);

    s1.print("s1 after move: ");
    s2.print("s2: ");

    cout << "\n--- Self Move Assignment ---\n";
    s2 = std::move(s2);
    s2.print("s2 self move: ");

    cout << "\n--- Chained Moves ---\n";
    MyString s3 = std::move(s2);
    MyString s4 = std::move(s3);

    s2.print("s2: ");
    s3.print("s3: ");
    s4.print("s4: ");

    cout << "\n--- Move Assignment ---\n";
    MyString s5("world");
    s5 = std::move(s4);

    s4.print("s4: ");
    s5.print("s5: ");

}
