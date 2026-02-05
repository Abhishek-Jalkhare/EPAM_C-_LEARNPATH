//
// Created by AbhishekJalkhare on 05-02-2026.
//
#include <iostream>
#include <vector>
using namespace std;

class Payment {
public:
    virtual void  process(double amount) = 0;
    virtual ~Payment() = default;
};

class CreditCardPayment : public Payment{
public:
    void process(const double amount) override {
        cout<<"Credit card payment processed of amount : "<<amount<<endl;
    }
};

class PayPalPayment : public  Payment {
public:
    void process(const double amount) override {
        cout<<"paypal payment processed of amount : "<<amount<<endl;
    }
};

int main(int argc, char* argv[]) {

    vector<Payment *> vec { new CreditCardPayment() ,new PayPalPayment() };
    for (auto p : vec) {
        p->process(12.4);
        delete p;
    }

}
