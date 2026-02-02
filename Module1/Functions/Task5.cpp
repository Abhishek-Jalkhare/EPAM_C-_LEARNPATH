//
// Created by AbhishekJalkhare on 02-02-2026.
//
#include <iostream>
using namespace std;


long long factorial(int n) {
    long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}


float term(float x, int n) {
    float power = 1.0f;
    int exponent = 2 * n - 1;


    for (int i = 1; i <= exponent; i++) {
        power *= x;
    }

    long long fact = factorial(exponent);

    if ((n + 1) % 2 == 0)
        return -power / fact;
    else
        return power / fact;
}


float sinTaylor(float x, int terms) {
    float sum = 0.0f;

    for (int i = 1; i <= terms; i++) {
        sum += term(x, i);
    }

    return sum;
}

int main() {
    float degree, radian;
    int terms;

    cout << "Enter angle in degrees: ";
    cin >> degree;

    cout << "Enter number of terms: ";
    cin >> terms;


    radian = degree * 3.14159265f / 180.0f;


    float result = sinTaylor(radian, terms);

    cout << "sin(" << degree << ") = " << result << endl;

    return 0;
}
