//
// Created by AbhishekJalkhare on 13-03-2026.
//

#ifndef CPPLEARNING_TASK6_H
#define CPPLEARNING_TASK6_H
#include <memory>
#include <string>


class Widget {
public:
    Widget();
    Widget(Widget&other) = delete;
    Widget(Widget&&other)noexcept;
    Widget& operator=(Widget& other) = delete;
    Widget& operator=(Widget&& other)noexcept;
    ~Widget();
    void setName(const std::string &);
    void printName() const;

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};


#endif //CPPLEARNING_TASK6_H