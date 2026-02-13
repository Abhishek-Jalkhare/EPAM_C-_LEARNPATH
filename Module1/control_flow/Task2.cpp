//
// Created by AbhishekJalkhare on 02-02-2026.
//
#include <iostream>
using namespace std;

int main() {
    double weight;
    char zone;
    double cost = 0.0;


    cout << "Enter order weight (in kg): ";
    cin >> weight;

    cout << "Enter shipping zone (A, B, or C): ";
    cin >> zone;

    
     if (weight <= 0 || weight > 100) {
         cout << "Error: Order weight must be positive.";
         return 0;
     }


    switch (zone) {

    case 'A':
        if (weight <= 2)
            cost = 100.0;
        else if (weight <= 10)
            cost = 200.0;
        else
            cost = 200.0 + (weight - 10) * 50.0;
        break;

    case 'B':
        if (weight <= 5)
            cost = 300.0;
        else
            cost = 300.0 + (weight - 5) * 50.0;
        break;

    case 'C':
        if (weight <= 5)
            cost = 500.0;
        else
            cost = 500.0 + (weight - 5) * 100.0;
        break;

    default:
        cout << "Error: Invalid shipping zone. Please enter A, B, or C.";
        return 0;
    }


    cout << "Total Shipping Cost: Rs. " << cost << endl;

    return 0;
}
