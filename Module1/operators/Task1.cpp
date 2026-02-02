//
// Created by AbhishekJalkhare on 02-02-2026.
//

#include <iostream>
using namespace std;
double fahrenheitToCelsius (double);

int main(int argc, char const *argv[])
{
    double f = 123.4;
    cout<<"Temperature in Fahrenheit : "<<fahrenheitToCelsius(f)<<endl;
    /* code */
    return 0;
}

double fahrenheitToCelsius( double f){
    double c = (f -32) *5/9;
    return c;
}