//
// Created by AbhishekJalkhare on 28-01-2026.
//

#include <iostream>
using namespace std;

class Item
{
public:
    Item()
    {
        cout<<"Constructor Ran"<<endl;
    }

    ~Item()
    {
        cout<<"Destructor Ran"<<endl;
    }

};

int main(int argc, char* argv[])
{
    Item* i1 = new Item();

    Item * arr = new Item[3];

    delete i1;
    delete[] arr;

    cout<<"Trying delete for array" << endl;
    Item * arr1 = new Item[3];
    delete arr1;
    // only onece destructor ran

}
