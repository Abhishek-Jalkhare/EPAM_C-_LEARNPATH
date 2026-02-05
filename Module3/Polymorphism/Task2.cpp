//
// Created by AbhishekJalkhare on 03-02-2026.
//
#include <iostream>
using namespace std;

class Complex {
    double real;
    double imag;

public:
    [[nodiscard]] double getReal() const {
        return real;
    }

    void setReal(const double real) {
        this->real = real;
    }

    [[nodiscard]] double getImag() const {
        return imag;
    }

    void setImag(const double imag) {
        this->imag = imag;
    }

    Complex(const double real, const double imag)
        : real(real),
          imag(imag) {
    }

    Complex operator+(const Complex& other) const{
        return  Complex{this->real + other.real , this->imag + other.imag};
    }
};

    ostream& operator<< (ostream& COUT ,const Complex& c) {
        COUT<<c.getReal() <<" + "<<c.getImag() <<"i";
        return COUT;
    }


int main(int argc, char* argv[]) {
    const Complex c1{1.3 , 3.6};
    const Complex c2{1.7 , 4.9};

    const Complex c3 = c1 + c2;

    cout<<"sum of complex c1 : "<<c1<< " and complex c2 : "<<c2 <<" is : "<< c3<<endl;
}
