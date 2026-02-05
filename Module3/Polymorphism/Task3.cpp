//
// Created by AbhishekJalkhare on 03-02-2026.
//

#include <iostream>
using namespace std;

class Fraction {
    int numerator ;
    int denominator{};

public:
    Fraction(const int numerator,const int denominator)
        : numerator(numerator) {
        setDenominator(denominator);
    }

    Fraction() {
        numerator = 1;
        denominator = 1;
    }

    [[nodiscard]] int getNumerator() const {
        return numerator;
    }

    void setNumerator(const int numerator) {
        this->numerator = numerator;
    }

    [[nodiscard]] int getDenominator() const {
        return denominator;
    }

    void setDenominator(const int denominator) {
        if (denominator == 0) {
            cout<<"Denominator can not be negative"<<endl;
            return;
        }
        this->denominator = denominator;
    }

    bool operator==(const Fraction& other) const {
        return  this->getNumerator() * other.denominator == this->getDenominator()*other.getNumerator();
    }

    bool operator<(const Fraction& other) const {
        return  this->getNumerator() * other.denominator < this->getDenominator()*other.getNumerator();
    }
};

    ostream& operator<<(ostream& COUT , const Fraction& f) {
        COUT<<f.getNumerator() << "/"<<f.getDenominator();
        return COUT;
    }


int main(int argc, char* argv[]) {
    Fraction f1{1,3};
    Fraction f2{1,2};

    cout<<"Fraction f1 : "<<f1<<endl;
    cout<<"Fraction f2 : "<<f2<<endl;
    cout<<"IS f1 == f2 : " << (f1==f2 ? "True" : "False") <<endl;
    cout<<"Is f1 < f2 : " << (f1 <f2 ? "True" : "False")<<endl;

}
