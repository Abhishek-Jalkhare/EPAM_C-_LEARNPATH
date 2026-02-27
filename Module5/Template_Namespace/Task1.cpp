
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


int main(int argc, char* argv[]) {
    Geometry::Point p{1,2};
    Geometry::printPoint(p);
}
