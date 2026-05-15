//
// Created by AbhishekJalkhare on 13-05-2026.
//
//
// Created by AbhishekJalkhare on 13-05-2026.
//


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class shape {
public:
    virtual void draw() = 0;
    virtual ~shape()= default;
};

class circle : public shape {
public:
    void draw() override {
        cout<<"Drawing circle"<<endl;
    }
};


class square : public  shape {
public:
    void draw() override {
        cout<<"Drawing Square"<<endl;
    }
};


class shape_factory {
public:
    virtual unique_ptr<shape> factoryMethod() = 0; // a factory method to create object
    void draw() { // some oeration method do execute a algorithm indpendent of the type
        factoryMethod()->draw();
    }
    virtual ~shape_factory() = default;
};

class square_factory : public shape_factory {
public:
    unique_ptr<shape> factoryMethod() override {
        return make_unique<square>();
    }
};

class circle_factory : public shape_factory {
public:
    unique_ptr<shape> factoryMethod() override {
        return make_unique<circle>();
    }
};

int main(int argc, char *argv[]) {
    unique_ptr<shape_factory> fact;

    fact = make_unique<square_factory>();
    fact->draw();

    fact = make_unique<circle_factory>();
    fact->draw();
}
