//
// Created by AbhishekJalkhare on 11-03-2026.
//

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class MyString {
    char* data;
public:
    MyString(const char* data) {
        this->data = new char[strlen(data) + 1];
        strcpy(this->data , data);
        cout<<"Parameterised Constructor Called"<<endl;
    }

    MyString (const MyString& other) {
        this->data = new char [strlen(other.data)+1];
        strcpy(this->data , other.data);
        cout<<"Copied resources to : "<<static_cast<void*>(this->data)<<endl;
    }

    MyString(MyString&& other) noexcept {
        this->data = other.data;
        other.data = nullptr;
        cout<<"Moved resources too : "<<static_cast<void*>(this->data)<<endl;
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
        cout<<"Destructor called"<<endl;
    }

    void printAddress(const char* label) const {
        cout<<label <<" address : "<<static_cast<void*>(data)<<endl;
    }

};


int main(int argc, char* argv[]) {
    vector<MyString> vec ;
    MyString a("hello");
    MyString b("hiii");

    std::cout << "\n-- push_back(a) (copy): --" << std::endl;
    vec.push_back(a);         // Calls copy constructor

    std::cout << "\n-- push_back(std::move(b)) (move): --" << std::endl;
    vec.push_back(std::move(b)); // Calls move constructor

    std::cout << "\n-- emplace_back(\"temp\"): --" << std::endl;
    vec.emplace_back("temp"); // Constructs in-place (calls direct constructor)

    std::cout << "\n-- push_back(\"temp\"): --" << std::endl;
    vec.push_back("temp");

}
