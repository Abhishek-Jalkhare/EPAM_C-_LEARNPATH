//
// Created by AbhishekJalkhare on 30-01-2026.
//
// vehicle model door dbl btry capcity

#include <iostream>
using namespace std;

class Vehicle {
    string make;
    string model;
public:
    Vehicle(const string& make , const string& model) {
        this->make = make;
        this->model = model;
        cout<<"Vehicle constructor ran"<<endl;
    }

};

class Car : public Vehicle {
    int doors;
public:
    Car(const string& make , const string& model , int doors ): Vehicle(make , model) {
        this->doors = doors;
        cout<<"car constructor ran"<<endl;
    }
};

class ElectricCar : public Car {
    double battercapcity ;
public:
    ElectricCar(const string& make , const string& model , int door , double batterycapacity) :
        Car(make , model ,door)  {
        this->battercapcity = batterycapacity;
        cout<<"Electric cAR constructor ran"<< endl;
    }

};



int main(int argc, char* argv[]) {
    Vehicle * v = new Vehicle("make" , "model1");
    delete v;
    v = new Car("make" , "model2" , 4);
    delete v;
    v = new ElectricCar("make" , "model2" , 6 , 3456.3);

    delete v;
}
