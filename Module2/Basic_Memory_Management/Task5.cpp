//
// Created by AbhishekJalkhare on 28-01-2026.
//

#include <iostream>
using namespace std;

class LeakDemo
{
public:
    LeakDemo()
    {
        cout<<"Leak Demo constructor ran" <<endl;
    }

    ~LeakDemo()
    {
        cout<<"Leak DEmo Destructor ran "<<endl;
    }
};

int main(int argc, char* argv[])
{
    // for (int i = 0; i < 1000; ++i)
    // {
    //     LeakDemo* d1 = new LeakDemo();
    // }

    // memory leak happens

    for (int i = 0; i < 1000; ++i)
    {
        LeakDemo* d1 = new LeakDemo();
        delete d1;
     //no memory leak becouse using delete every time
    }
}

