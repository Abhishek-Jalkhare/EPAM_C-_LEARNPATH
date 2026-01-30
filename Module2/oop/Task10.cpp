//
// Created by AbhishekJalkhare on 30-01-2026.
//



#include <iostream>
#include <vector>

using namespace std;

class Shape {
public:
    [[nodiscard]] virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void display() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
    double r;
public:
    explicit Circle(double radius) : r(radius) {}


    double radius() const {
        return r;
    }

    double area() const override {
        return 3.14159 * r * r;
    }

    double perimeter() const override {
        return 2 * 3.14159 * r;
    }

    void display() const override {
        cout << "Circle\n";
        cout << "Radius: " << r << "\n";
        cout << "Area: " << area() << "\n";
        cout << "Perimeter: " << perimeter() << "\n\n";
    }
};

class Square : public Shape {
    double side;
public:
    explicit Square(double side) : side(side) {}

    double getSide() const {
        return side;
    }

    double area() const override {
        return side * side;
    }

    double perimeter() const override {
        return 4 * side;
    }

    void display() const override {
        cout << "Square\n";
        cout << "Side: " << side << "\n";
        cout << "Area: " << area() << "\n";
        cout << "Perimeter: " << perimeter() << "\n\n";
    }
};

class Rectangle : public Shape {
    double length;
    double width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double getLength() const {
        return length;
    }

    double getWidth() const {
        return width;
    }

    double area() const override {
        return length * width;
    }

    double perimeter() const override {
        return 2 * (length + width);
    }

    void display() const override {
        cout << "Rectangle\n";
        cout << "Length: " << length << "\n";
        cout << "Width: " << width << "\n";
        cout << "Area: " << area() << "\n";
        cout << "Perimeter: " << perimeter() << "\n\n";
    }
};

int main() {
    Circle c(5);
    Square s(4);
    Rectangle r(6, 3);

    c.display();
    s.display();
    r.display();

    vector<Shape*> shapes;
    shapes.push_back(&c);
    shapes.push_back(&s);
    shapes.push_back(&r);

    cout << "Polymorphic Access\n";
    for (const Shape* shape : shapes) {
        cout << "Area: " << shape->area() << "\n";
        cout << "Perimeter: " << shape->perimeter() << "\n\n";
    }

    cout << "Circle radius: " << c.radius() << endl;

    return 0;
}
