//
// Created by AbhishekJalkhare on 13-03-2026.
//


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#include <iostream>
#include <memory>

class Widget {
public:
    Widget() { std::cout << "Widget constructed at " << this << std::endl; }
    ~Widget() { std::cout << "Widget destructed at " << this << std::endl; }
    void greet() const { std::cout << "Hello from Widget at " << this << std::endl; }
};

std::unique_ptr<Widget> makeWidget() {
    auto ptr = std::make_unique<Widget>();
    ptr->greet();
    return ptr; // Ownership moves to caller! as make_unique have no copy constructor
    // so compiler automatically does somthing like move(ptr) this transfer ownership of ptr to return valu

}

int main(int argc, char* argv[]) {
    std::cout << "== Smart pointer (unique_ptr) example ==\n";
        {
            auto widgetPtr = makeWidget();
            widgetPtr->greet();
        } // unique_ptr goes out of scope, deletes object here

        std::cout << "== Manual new/delete (anti-pattern) ==\n";
        {
            Widget* w = new Widget();
            w->greet();
            delete w; // forget this line and you have a leak!
        }
    std::cout << "Program end." << std::endl;
    return 0;


}
