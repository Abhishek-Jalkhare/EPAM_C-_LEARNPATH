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
    static unique_ptr<shape> create_shape(const string& s) {
        if (s == "circle") return make_unique<circle>();
        if (s == "square") return  make_unique<square>();
        return nullptr;
    }
};

int main(int argc, char *argv[]) {
    unique_ptr<shape> p1 = shape_factory::create_shape("circle");
    if (p1)
        p1->draw();
    unique_ptr<shape> p2 = shape_factory::create_shape("square");
    p2->draw();
}
