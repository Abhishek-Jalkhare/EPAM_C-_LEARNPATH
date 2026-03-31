//
// Created by AbhishekJalkhare on 12-03-2026.
//
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Base {
protected:
    int* baseData;
public:
    Base():baseData(new int(0)) {
        cout<<"Default constructor of Base Ran"<<endl;
    }

    Base(const Base& other): baseData(new int(*(other.baseData))){
        cout<<"Copy Constructor of base Ran"<<endl;
    }

    Base(Base&& other)noexcept :baseData(other.baseData) {
        other.baseData = nullptr;
        cout<<"Move Constructor of base Ran"<<endl;
    }

    Base& operator=(const Base& other) {
        if (this == &other) return *this;
        delete this->baseData;
        this->baseData = new int(*other.baseData);
        cout<<"Copy Assingment Operations of base class"<<endl;
        return *this;
    }

    Base& operator=(Base&& other) noexcept {
        if (this == &other) return *this;
        delete this->baseData;
        this->baseData = other.baseData;
        other.baseData = nullptr;
        cout<<"Move Operations of Base class Ran"<<endl;
        return *this;
    }
    virtual void print(const char* lbl) const {
        std::cout << lbl << " Base data: " << baseData << " (" << (baseData ? *baseData : 0) << ")\n";
    }

    virtual ~Base() {
        delete baseData;
        cout<<"Destructor of base ran"<<endl;
    }

};

class Derived : public Base {
    char* derivedData;
public:
    Derived():derivedData(new char('a')) { // use  base default constructor to intialise base part
        cout<<"Default constructor of Derived Ran"<<endl;
    }
    // use base copy constructor to intialise base part
    Derived(const Derived& other):Base(other) ,derivedData(new char(*other.derivedData)) {
        cout<<"Derived Copy Constructor Ran"<<endl;
    }
    // use base move constructor by using move() on the value
    Derived(Derived && other) noexcept : Base(std::move(other)) , derivedData(other.derivedData) {
        other.derivedData = nullptr;
        cout<<"Move Constructor of Derived Called "<<endl;
    }
    // use Base::operator= to set base part value;
    Derived& operator=(const Derived& other) {
        if (this == & other) return *this;
        Base::operator=(other);
        delete this->derivedData;
        this->derivedData = new char(*other.derivedData);
        return *this;
    }
 // use Base::operator=(move(a)) to set base part
    Derived& operator=(Derived&& other) noexcept{
        if (this == &other) return  *this;
        Base::operator=(std::move(other));
        delete this->derivedData;
        this->derivedData = other.derivedData;
        other.derivedData = nullptr;
        return *this;
    }

    void print(const char* lbl) const override {
        Base::print(lbl);
        std::cout << lbl << " Derived data: " << static_cast<const void*>(derivedData)
                  << " (" << (derivedData ? derivedData : "null") << ")\n";
    }

     ~Derived() override {
        delete derivedData;
        cout<<"Destructor of Derived called"<<endl;
    }
};


int main(int argc, char* argv[]) {
    std::cout << "--- Base test ---\n";
    Base b1;
    Base b2 = b1;       // Copy
    b2 = std::move(b1); // Move assign

    std::cout << "--- Derived test ---\n";
    Derived d1;
    Derived d2 = d1;    // Copy ctor
    d2 = std::move(d1); // Move assign

    std::cout << "--- Slicing demo ---\n";
    Base sliced = d2;   // Slicing (loses Derived-specific data)
    sliced.print("sliced: ");
    d2.print("d2: ");

    std::cout << "--- Polymorphic deletion ---\n";
    Base* poly = new Derived();
    delete poly;        // Should call both destructors safely
    return 0;
}
