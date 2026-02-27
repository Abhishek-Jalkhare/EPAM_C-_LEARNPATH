//
// Created by AbhishekJalkhare on 25-02-2026.
//
#include <iostream>
namespace Geometry {
    struct Point {
        int x , y;
    };
    void printPoint(Point & p) {
        std::cout<<"x : "<<p.x <<", y : "<<p.y<<std::endl;
    }
}

namespace G = Geometry;

int main(int argc, char* argv[]) {
    G::Point p{1,4};
    G::printPoint(p);
}
