//
// Created by AbhishekJalkhare on 13-02-2026.
//
#include <iostream>
#include <stdexcept>
using namespace std;

class SystemError : public exception {
    string message;
public:
    explicit SystemError(const string& msg):message(msg)  {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class NetworkError : public exception {
string message;
public:
explicit NetworkError(const string& msg):message(msg)  {}
    const char* what() const noexcept override {
    return message.c_str();
}
};

inline static int count  = 0;
void complexOperation() {
    count++;
    switch (count) {
    case 1 : {
        throw SystemError{"System error encountered"};

    }
    case 2 : {
        throw NetworkError{"Network Error encountered"};

    }
    case 3 : {
        throw -1;
    }
    case 4: {
        throw "Very Unexpected Error!";

    }
    default: {
        cout<<"Operation Completed Succesfully"<<endl;
    }
    // count++; can't write count here because control never reaches here exception
    // thrown and function exits so increment first
    }
}

int main(int argc, char* argv[]) {
    int n = 5 , i = 0;
    while (i < n) {
        try {
            complexOperation();
        }
        catch(const NetworkError& error) {
            cout<<"Network error caught: "<<string{error.what()}<<endl;
        }
        catch(const SystemError& error) {
            cout<<"System error caught: "<<string{error.what()}<<endl;
        }
        catch (int errorCode) {
            cout<< "Generic integer error caught: " <<endl;
        }
        catch (...) {
            cout<<"Unknown exception caught!"<<endl;
        }
        cout<< "--- End of processing ---"<<endl;
        i++;
    }
}


