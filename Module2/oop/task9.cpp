//
// Created by AbhishekJalkhare on 30-01-2026.
//
#include<iostream>
using namespace  std;

 class Printable {
public:
     virtual ~Printable() = default;
     virtual void print() = 0;
};

class Savable {
public:
    virtual void save() = 0;
    virtual ~Savable() = default;
};

class Document : public  Printable ,public Savable {
public:
    void print() override {
        cout<<"Document printed"<<endl;
    }

    void save() override {
        cout<<"document saved"<<endl;
    }
};


int main(int argc, char* argv[]) {
    Document d;
    d.print();
    d.save();
}
