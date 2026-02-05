//
// Created by AbhishekJalkhare on 05-02-2026.
//



#include <iostream>
#include <vector>
using  namespace std;

class Shape {
    string name;

public:
    explicit Shape(const string& name)
        : name(name) {
    }

    [[nodiscard]] string getName() const {
        return name;
    }

    virtual double area() = 0;
    virtual ~Shape() {
        cout<<"Shape destructor called"<<endl;
    }
};

class Circle : public Shape {
    double r;

public:
    Circle(int r) : Shape("Circle"){
        setR(r);
    }

    [[nodiscard]] double getR() const {
        return r;
    }

    void setR(double r) {
        if (r <= 0) {
            cout<<"can't assign r , r should be positive"<<endl;
            return;
        }
        this->r = r;
    }

    double area() override {
        return 3.14 * r * r;
    }

    ~Circle() override {
        cout<<"Circle destructor called"<<endl;
    }
};

class Rectangle : public  Shape {
    double l , b;

public:
    Rectangle( double l, double b)
        : Shape("Rectangle"){
        setL(l);
        setB(b);

    }

    [[nodiscard]] double getL() const {
        return l;
    }

    void setL(double l) {
        if (l <= 0) {
            cout<<"Can't assign length , length should alwas be positive"<<endl;
            return;
        }
        this->l = l;
    }

    [[nodiscard]] double getB() const {
        return b;
    }

    void setB(double b) {
        if (b <= 0) {
            cout<<"Can't assign length , length should alwas be positive"<<endl;
            return;
        }

        this->b = b;
    }

    double area() override {
        return l*b;
    }

    ~Rectangle() override{
        cout<<"Rectangel destroyed"<<endl;
    }
};

class Square : public Shape {
    double s;

public:
    [[nodiscard]] double getS() const {
        return s;
    }

    void setS(int s) {
        this->s = s;
    }

    explicit Square(double s)
        : Shape("Square") {
        setS(s);
    }

    double area() override {
        return s*s;
    }

    ~Square() override {
        cout<<"Square destroyed"<<endl;
    }
};

int main(int argc, char* argv[]) {
    vector<Shape*> vec = { new Circle(12) , new Rectangle(12,2)  ,new Square(12)};

    for (Shape* s: vec) {
        cout<<"Name of shape : "<<s->getName()<<endl;
        cout<<"Area of shape : "<<s->area()<<endl;
        cout<<"---------------------"<<endl;

        delete s;
    }
}