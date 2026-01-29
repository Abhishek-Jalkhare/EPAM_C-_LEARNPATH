//
// Created by AbhishekJalkhare on 29-01-2026.
//
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class Shape {
public:
    virtual double area () = 0;
    virtual  double perimeter() = 0;

    virtual ~Shape() = default;
};

class Circle : public Shape {
    int r{};
public:
    Circle(const int r) {
       setRadius(r);
    }

    [[nodiscard]] int getR() const {
        return r;
    }

    void setRadius(int r) {
        if (r < 0) {
            cout<<"Enter a valid value"<<endl;
            return;
        }

        this->r = r;
    }

    double area() override {
        return 3.14 * r *r;
    }

    double perimeter() override {
        return 2*3.14*r;
    }
};

class Triangle : public Shape{
    int a;
    int b ;
    int c;

public:
    Triangle(int a,int b, int c){

        setA(a);
        setB(b);
        setC(c);
    }
    [[nodiscard]] int getA() const {
        return a;
    }

    void setA(int a) {
        if (a  < 0) {
            cout<<"Enter a valid side length"<<endl;
            return;
        }
        this->a = a;
    }

    [[nodiscard]] int getB() const {
        return b;
    }

    void setB(int b) {
        if (b  < 0) {
            cout<<"Enter a valid side length"<<endl;
            return;
        }
        this->b = b;
    }

    [[nodiscard]] int getC() const {
        return c;
    }

    void setC( int c) {
        if (c  < 0) {
            cout<<"Enter a valid side length"<<endl;
            return;
        }
        this->c = c;
    }

    double perimeter() override {
        return a + b + c;
    }

    double area() override {
        const double s = static_cast<double>(a + b + c)/2;
        return sqrt((s*(s-a)*(s-b)*(s-c)));
    }
};

class Rectangle : public Shape{
    int length{};
    int breadth{};

public:
    [[nodiscard]] int getLength() const {
        return length;
    }

    void setLength(int length) {
        this->length = length;
    }

    [[nodiscard]] int getBreadth() const {
        return breadth;
    }

    void setBreadth(int breadth) {
        this->breadth = breadth;
    }

    Rectangle(const int length , const int breadth) {
        setBreadth(breadth);
        setLength(length);
    }

    double perimeter() override {
        return 2 *(length + breadth);
    }

    double area() override {
        return  length * breadth;
    }


};

int main(int argc, char* argv[]) {
   vector<Shape*> vec;
    Shape* circle = new Circle(2);
    vec.push_back(circle);
    Shape* triangle = new Triangle(1,2,3);
    vec.push_back(triangle);
    Shape* rectangle = new Rectangle(4,3);
    vec.push_back(rectangle);

    for (Shape * s : vec) {
        cout<<"Area of shape : "<<s->area()<<endl;
        cout<<"Perimeter of shape : "<<s->perimeter() <<endl;
    }

    delete rectangle;
    delete triangle;
    delete circle;

}
