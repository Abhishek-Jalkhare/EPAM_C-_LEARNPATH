//
// Created by AbhishekJalkhare on 29-01-2026.
//
#include <iostream>
using namespace std;

class Payment {
public:
    virtual void  processPayment(double amount) = 0;
    virtual ~Payment() = default;
};

class CreditCardPayment : public Payment{
public:
    void processPayment(const double amount) override {
        cout<<"Credit card payment processed of amount : "<<amount<<endl;
    }
};

class PayPalPayment : public  Payment {
public:
    void processPayment(const double amount) override {
        cout<<"paypal payment processed of amount : "<<amount<<endl;
    }
};

int main(int argc, char* argv[]) {
    Payment * p = new CreditCardPayment();
    p->processPayment(12.4);

    p = new PayPalPayment();
    p->processPayment(124);

    delete p;
}
