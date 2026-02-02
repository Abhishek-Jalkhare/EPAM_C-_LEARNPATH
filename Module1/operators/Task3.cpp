//
// Created by AbhishekJalkhare on 02-02-2026.
//
#include <iostream>
using namespace std;

int main() {
    int totalDays;
    int years, weeks, days;

    cout << "Enter total number of days: ";
    cin >> totalDays;

    years = totalDays / 365;
    days = totalDays % 365;

    weeks = days / 7;
    days = days % 7;

    cout << "Years: " << years << endl;
    cout << "Weeks: " << weeks << endl;
    cout << "Days: " << days << endl;

    return 0;
}
