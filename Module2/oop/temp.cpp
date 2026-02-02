//
// Created by AbhishekJalkhare on 02-02-2026.
//
#include<iostream>
using namespace std;

class Animal {
public:
     virtual void speak() {
        cout<<"Animal speaks"<<endl;
    }

};

class Dog : public Animal {
public:
    void speak() override{
        cout<<"Dog speaks"<<endl;
    }
    void printXYZ() {
        cout<<"hcbvjhcd"<<endl;
    }

};

int main(int argc, char* argv[]) {
    Animal * a = new Dog();
    a->speak();
    // a->printXYZ(); we can not access dog method through animal type
    // this is also dangerous because if Animal * a  = new Cat()
    //then cat might not have same method
    //Pointer type controls accessibility, object type controls behavior (via virtual functions)

}
