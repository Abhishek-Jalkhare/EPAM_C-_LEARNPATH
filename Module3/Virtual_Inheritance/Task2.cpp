//
// Created by AbhishekJalkhare on 04-02-2026.
//

#include <iostream>
using namespace std;

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

    Device () = default;

    virtual ~Device() = default;
};

class Phone :virtual public Device {
protected:
    string phoneModel; // if

    explicit Phone(const string& phone_model)
        : phoneModel(phone_model) {
    }
};

class Camera :virtual public Device {
protected:
    string megaPixel;

    explicit Camera(const string& mega_pixel)
        : megaPixel(mega_pixel)  {
    }
};

class SmartPhone : public Phone , public Camera {
    int price;
public:
    SmartPhone(int id, const string& name, const string& phoneModel, const string& megaPixel, int price) :
        Device(id, name),
       Phone(phoneModel),Camera(megaPixel), price(price) {

    }

    void displayParent() {
        cout<<(Device*)((Camera *)this)<<endl;
    }
};


int main(int argc, char* argv[]) {

}
