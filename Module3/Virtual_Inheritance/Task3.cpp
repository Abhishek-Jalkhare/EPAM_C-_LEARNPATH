//
// Created by AbhishekJalkhare on 05-02-2026.
//
#include <iostream>
using namespace std;

class Device {

public:
    int id;
    Device(int id) {
        this->id = id;
        cout<<"Device constructor called"<<endl;
    }
    Device() = default;
};

class Phone : public virtual Device {
public:
    Phone() {
        cout<<"phone constructor called"<<endl;
    }
};

class Camera : public virtual Device {
public:
    Camera() {
        cout<<"Camera constructor called"<<endl;
    }
};

class SmartPhone : public Camera , public  Phone {
public:
    SmartPhone(int id) : Device(id) {
        cout<<"SmartPhone Constructor called"<<endl;
    }

};

int main(int argc, char* argv[]) {
    // SmartPhone smart_phone(); compiler may think this is a function declaration
    SmartPhone smart_phone{1};
    cout<<(smart_phone.id)<<endl;


}
// we get the output as :
// Device constructor called
// Camera constructor called
// phone constructor called
// SmartPhone Constructor called
// this shows that only one subobject of virtual base is created
// and the order of constructor calling is virtual base , base , child