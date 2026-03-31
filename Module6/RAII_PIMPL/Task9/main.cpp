//
// Created by AbhishekJalkhare on 16-03-2026.
//
#include "bigdata.h"
#include <iostream>

int main(int argc, char* argv[]) {
    bigdata bd;
    bd.process();
    std::cout << "BigData size: " << bd.getSize() << std::endl;
    return 0;
}
