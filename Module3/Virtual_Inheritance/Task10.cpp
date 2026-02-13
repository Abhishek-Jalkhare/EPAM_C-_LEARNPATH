//
// Created by AbhishekJalkhare on 05-02-2026.
//
#include <iostream>
using namespace std;

class LivingBeing {
public:
    string name;
    void show() const {
        cout<<"Name : "<<name <<endl;
        cout<<"address of Living Object : "<<this<<endl;
    }
};

class Animal  :public virtual  LivingBeing {

};

class Plant :public virtual  LivingBeing {

};

class Hybrid : public Animal , public  Plant {

};

int main(int argc, char* argv[]) {
    Hybrid hybrid;
    hybrid.name = "Chimera";
    cout<<"Calling show through animal : ";
   ((Animal*)&hybrid)->show();
    cout<<"Calling show through Plant : ";
    ((Plant*)&hybrid)->show();
    // getting same address tells that the only one subobject exist
}
    