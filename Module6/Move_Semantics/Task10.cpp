//
// Created by AbhishekJalkhare on 11-03-2026.
//
#include <iostream>
#include <cstring>
using namespace std;

class MyString {
    char* data;
public:
     explicit MyString(const char* data) {
        this->data = new char[strlen(data) + 1];
        strcpy(this->data , data);
        cout<<"Parameterised Constructor Called"<<endl;
    }

    MyString (const MyString& other) {
         this->data = new char [strlen(other.data)+1];
         strcpy(this->data , other.data);
    }

    MyString(MyString&& other) noexcept {
         this->data = other.data;
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
          cout<<"Destructor called"<<endl;
     }

     void printAddress(const char* label) const {
          cout<<label <<" address : "<<static_cast<void*>(data)<<endl;
     }

};

void printAddress(MyString&& s) {
     s.printAddress("s");
}

template<typename T>
void forwardToPrint(T&& str) {
     printAddress(forward<T>(str));
}

int main(int argc, char* argv[]) {
     MyString s1("lvalue");
     printAddress(std::move(s1));                 // Moves s1

     std::cout << "---" << std::endl;

     printAddress(MyString("rvalue"));            // Moves the temp

     std::cout << "--- Forwarding ---" << std::endl;

     forwardToPrint(MyString("temp"));            // Forwards rvalue (calls move)
     forwardToPrint(std::move(s1));               // Forwards rvalue for moved-from s1

     MyString s2("Lvalue string");
     // forwardToPrint(s2); this will give error because forward to print will give lval
     // to the printaddress but it donot accept lvalue

}
