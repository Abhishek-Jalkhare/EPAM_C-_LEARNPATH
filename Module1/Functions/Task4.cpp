//
// Created by AbhishekJalkhare on 02-02-2026.
//
#include <iostream>
using namespace std;

long long factorial(int n){
    if(n <=1) return 1;
    return n * factorial(n -1);
}

float term (float x , int n){
    return pow(x, n) / factorial(n);
}

float expTaylor(float x , int terms =10){
    float sum =0.0;
    for (int n =0; n < terms; n++){
        sum += term(x, n);
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    /* code */
    int x;
    cout<<"Enter value of x to compute e^x using Taylor Series: ";
    cin>>x;
    int n;
    cout<<"Enter number of terms for approximation (default 10): ";
    cin>>n;
    float result = expTaylor(x, n);
    cout<<"Approximation of e^"<<x<<" using "<< n <<" terms is: "<< result <<endl;

    return 0;
}
