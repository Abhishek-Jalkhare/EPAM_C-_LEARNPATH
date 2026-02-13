//
// Created by AbhishekJalkhare on 09-02-2026.
//

#include "virtual_upcast.h"
#include <iostream>
using namespace std;

class Top{
public:
    int a;
};
class Left :public Top{
public:
    int b;
};
class Right :public Top{
public:
    int c;
};

class Bottom : public  Left, public  Right {
public:
    int d;
};


int main(int argc, char* argv[]) {
    Bottom* b = new Bottom{};

    Left*l = (Left*)b;
    Right*r = (Right*)b; // g++ does this

    // Top * t = (Top*)b; ambigious

    // nowww
    Top*t1 = (Top*)(Left*)b;
    Top*t2 = (Top*)(Right*)b;


  //  cout<<d <<" ,"<<c<<" ,"<<b;
    cout<<t1 <<" ,"<<t2;
    int a;
    cin >> a;


}
