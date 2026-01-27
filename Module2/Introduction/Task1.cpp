//
// Created by AbhishekJalkhare on 27-01-2026.
//
#include <iostream>
#include <set>
using namespace std;

class Rectangle {
    int length{}; // default access specifier private
    int width{};


public:



    [[nodiscard]] int getLength() const { // const member fuction gurantess that
        // it will not modify object state
        return this->length;
    }

    [[nodiscard]] int getWidth() const {
        return width;
    }

    void setLength (int length) {
        this->length = length;
    }

    void setWidth (int width) {
        this->width = width;
    }

    Rectangle(const int length , const int width) {
        setLength(length);
        setWidth(width);
    }

};

struct Point {
    int x ; // default access specifier public
    int y ;

};

int main(int argc, char *argv[]) {
    Point p{};
    p.x = 12;
    p.y = 12;

    cout<<"X COrdinate of point : " << p.x<< " y cordinate of point : "<<p.y<<endl;

    Rectangle r(10 , 12) ;
    // r.length = 12 this is invalid
    int l = r.getLength();
    int w = r.getWidth();

    cout<<"LEngth and width of rectangele : " << l <<" , "<< w;





}

