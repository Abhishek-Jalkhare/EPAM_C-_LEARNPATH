//
// Created by AbhishekJalkhare on 04-02-2026.
//
#include <iostream>
using namespace std;
// In virtual inheritance, the
// virtual base class is
//  constructed exactly once by the most derived class
// ,
//  must be default
// -
// constructible
// if
// intermediate classes are instantiated, and should be initialized only in the most derived
// class
// using initializer
// lists
// .

class Device { // if we define any constructor the ompiler do not genrate a default one
    inline static int deviceCount = 0;
    int id ;
    string name;

public:
    Device(const int id, const string& name)
        : id(id),
          name(name) {
        deviceCount++;
        cout<<deviceCount<<" instance of device count present"<<endl;
    }

    void showDeviceInfo() const {
        cout<<"Device Name : " << name<<endl;
        cout<<"Device id : " << id<<endl;
    }

    void printDeviceAddress() const {
        cout<<this<<endl;
    }

    Device () = default;

    virtual ~Device() = default;
};

class Phone :virtual public Device {
protected:
    string phoneModel; // if

    explicit Phone(const string& phone_model)
        : phoneModel(phone_model) {
    }
public:
    void printDeviceAddress() {
        cout<<"Device address through Phone : "<<(Device*)this<<endl;
    }

};

class Camera : virtual public Device {
protected:
    string megaPixel;

    explicit Camera(const string& mega_pixel)
        : megaPixel(mega_pixel)  {
    }

public:
    void printDeviceAddress() {
        cout<<"Device address through Camera : "<<(Device*)this<<endl;
    }
};

class SmartPhone : public Phone , public Camera {
    int price;
public:
    SmartPhone(int id, const string& name, const string& phoneModel, const string& megaPixel, int price) :
        Device(id, name),
       Phone(phoneModel),Camera(megaPixel), price(price) {

    }
    void printDeviceAddress() {
        Camera::printDeviceAddress();
        Phone::printDeviceAddress();

        cout<<"Device address using Smartphone"<<(Device*)this<<endl;
    }
};

int main(int argc, char* argv[]) {
    SmartPhone s{1 , "a", "model1","3mp",133};
    s.printDeviceAddress();
    s.showDeviceInfo();

}



