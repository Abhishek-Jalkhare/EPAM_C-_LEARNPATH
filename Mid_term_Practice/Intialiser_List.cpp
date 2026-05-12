//
// Created by AbhishekJalkhare on 07-05-202

#include <iostream>

template<typename T>
class List {
    std::initializer_list<T> li;
public:
    List( std::initializer_list<T> li) : li(li) {

    }
    void print() {
        for (auto i : li) {
            std::cout<<i<<" ";
        }
    }
};

int main(int argc, char *argv[]) {
    List l{1,2,3,45};
    l.print();
}
