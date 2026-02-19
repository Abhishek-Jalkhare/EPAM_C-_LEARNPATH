//
// Created by AbhishekJalkhare on 12-02-2026.
//
#include <iostream>
using  namespace std;

class Box {
    double length , breadth , height;

public:
    Box(const double length, const double breadth, const double height)
        : length(length),
          breadth(breadth),
          height(height) {
    }

    friend double vol(const Box& b) {
        return  b.length*b.breadth*b.height;
    }
};

// double vol(const Box& b) {
//     return  b.length*b.breadth*b.height;
// }

int main(int argc, char* argv[]) {
    const Box box{2.0 , 3.0 , 5.0};
    cout<<"Volume of Box : "<<vol(box);
}
