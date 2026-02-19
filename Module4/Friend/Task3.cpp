//
// Created by AbhishekJalkhare on 12-02-2026.
//
#include <iostream>
#include<cstring>
#include <cmath>
using namespace std;
class Circle;
class Rectangle {
    double length , breadth;

public:
    Rectangle(double length, double breadth)
        : length(length),
          breadth(breadth) {
    }
    friend double compareArea(const Rectangle& rec , const Circle& cir );
};

class Circle {
    double r;

public:
    explicit Circle(double r)
        : r(r) {
    }
    friend double compareArea(const Rectangle& rec , const Circle& cir );
};

double compareArea(const Rectangle& rec , const Circle& cir ) {
    const double rec_area = rec.breadth * rec.length;
    const double cir_area = M_PI*cir.r*cir.r;
    return (rec_area >= cir_area ? rec_area : cir_area);
}


int main(int argc, char* argv[]) {
    const Rectangle r{2,3};
    const Circle c{2.3};
    cout<<compareArea(r , c)<<endl;
    const Rectangle r1{1,2};
    cout<<compareArea(r1 , c)<<endl;
    // int p=nullptr;
    // stod();
    // stoi();
    // to_string();
    // to_string();

}
