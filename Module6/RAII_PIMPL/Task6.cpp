//
// Created by AbhishekJalkhare on 13-03-2026.
//

#include "Task6.h"
#include <iostream>

using namespace std;

struct Widget::Impl{
    string name;
};

Widget::Widget():impl(make_unique<Impl>()) {}

Widget::~Widget() = default;

Widget::Widget(Widget&& other) noexcept : impl( std::move(other.impl)){

}

Widget& Widget::operator=(Widget&& other) noexcept{
    if (&other != this) {
        this->impl = std::move(other.impl);
    }
    return *this;
}

void Widget::printName() const {
    cout<<"Name of Widget : "<<impl->name;
}

void Widget::setName(const string& name) {
    impl->name = name;
}


int main(int argc, char* argv[]) {
    Widget w;
    w.setName("widget");
    w.printName();
}



