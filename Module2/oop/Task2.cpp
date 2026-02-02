//
// Created by AbhishekJalkhare on 02-02-2026.
//

#include<iostream>
using namespace std;

class Temprature {
    double celsius;

public:
    [[nodiscard]] double getCelsius() const {
        return celsius;
    }

    void setCelsius(const double celsius) {
        if (celsius < -273.15) {
            cout<<"Invalid celsius value"<<endl;
            return;
        }
        this->celsius = celsius;
    }

    [[nodiscard]] double getFahrenheit()  const {
        double f = (this->celsius * 9/5) + 32;
        return f;
    }
};

int main(int argc, char* argv[]) {
    Temprature t{};
    t.setCelsius(-324);//can not set because invalidvalue
    t.setCelsius(123);
    cout<<"Celsius Value : "<<t.getCelsius(); // using getters to get the value of celsius
    cout<<"Fahrenheit value : "<<t.getFahrenheit(); //
    // t.celsius = 234; this gives error inaccessible member


}