//
// Created by AbhishekJalkhare on 27-01-2026.
//
#include<iostream>
using namespace  std;

class Box {
public:
    int length;
    int width;
    int height;

    void setDimension(int length , int width , int height) {
        this->length = length;
        this->width = width;
        this->height = height;
    }

    Box compareVolume(const Box& b) const {
        if (this->length * this->width * this->height >= b.length * b.width * b.height) return *this;
        else return b;
    }


};

int main(int argc, char *argv[]) {
    Box b1{};
    b1.setDimension(2,4,6);
    Box b2{};
    b2.setDimension(1,3,2);

    Box biggerBox = b1.compareVolume(b2);

    cout<<"Bigger box : l : "<<biggerBox.length << endl;
    cout<<"Bigger box : w : "<<biggerBox.width << endl;
    cout<<"Bigger box : h : "<<biggerBox.height << endl;

}


