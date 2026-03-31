//
// Created by AbhishekJalkhare on 13-03-2026.
//

#ifndef CPPLEARNING_WIDGET_H
#define CPPLEARNING_WIDGET_H
#pragma once
#include <memory>
#include <string>

class Widget {
public:
    Widget();
    Widget(Widget& ) = delete;
    Widget(Widget&& ) = default;
    Widget& operator=(Widget&) = delete;
    Widget& operator=(Widget&&) = default;

    ~Widget();

    void setName(const std::string &name);
    void printData() const;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};




#endif //CPPLEARNING_WIDGET_H