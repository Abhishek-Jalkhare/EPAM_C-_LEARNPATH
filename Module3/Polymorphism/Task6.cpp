//
// Created by AbhishekJalkhare on 03-02-2026.
//

#include <iostream>
using namespace std;

// Virtual dispatch applies only to the function body,
// default arguments are resolved at compile time based on the pointer type

//Default arguments are statically bound, so when a virtual function is
//called through a base-class pointer, the base-class default
//argument is used even though the derived function body executes.

class Printer {
public:
    virtual void print (const string &msg = "Base Printer") const{
        cout<<msg<<endl;
    }

    virtual ~Printer() = default;
};

class ColorPrinter : public Printer {
public:
    void print(const string& msg = "Color Printer") const override {
        cout<<msg<<endl;
    }
};

int main(int argc, char* argv[]) {
    ColorPrinter * cp  = new ColorPrinter();
    cout<<"Calling print() through Colorprinter type pointer"<<endl;
    cp->print();

    Printer * ptr = new ColorPrinter();
    cout<<"Calling print() through Printer type pointer"<<endl;
    ptr->print();

    delete cp;
    delete ptr;
}

