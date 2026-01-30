//
// Created by AbhishekJalkhare on 30-01-2026.
//

#include <iostream>
using namespace std;

class Device {

    int id;
    string name ;

public:
    Device(int id , const string &name) {
        this->name = name;
        this->id = id;
        cout<<"Device intialised"<<endl;
    }

    [[nodiscard]] int get_id() const {
        return id;
    }

    void set_id(const int id) {
        this->id = id;
    }

    [[nodiscard]] string get_name() const {
        return name;
    }

    void set_name(const string& name) {
        this->name = name;
    }
};

class Phone :  virtual public Device {
public:
    Phone(int id, const string& name ) : Device(id , name) {
        cout << "Phone intialised" << endl;
    }
};

class Camera :  vir public  Device{
public:
    Camera(int id, const string& name) : Device(id,name){
        cout<<"camera initialise"<<endl;
    }
};


class SmartPhone : public Camera , public Phone {
public:
    SmartPhone(int id , const string& name): Camera(id , name) , Phone(id , name) {
        cout<<"Smart Phone is intialised"<<endl;
    }
};


int main(int argc, char* argv[]) {
    SmartPhone * p = new SmartPhone(1 , "a");
    p->set_id(12);
    delete p;
}
