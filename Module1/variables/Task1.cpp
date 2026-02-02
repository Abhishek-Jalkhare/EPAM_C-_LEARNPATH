//
// Created by AbhishekJalkhare on 02-02-2026.
//
#include <iostream>
using namespace std;

int main() {
    char code = 'C';
    cout << code << " represents sensor type code" << endl;

    int sensorID = 101;
    cout << "Sensor ID: " << sensorID << endl;

    float temperature = 36.5f;
    cout << "Temperature: " << temperature << " °C" << endl;

    double humidity = 65.789432;
    cout << "Humidity: " << humidity << " %" << endl;

    bool systemStatus = true;
    cout << "System Status: " << (systemStatus ? "Active" : "Inactive") << endl;

    short smallValue = 12;
    long largeValue = 100000L;
    long long veryLargeValue = 1234567890123LL;
    unsigned int count = 250;
    unsigned char level = 200;

    cout << "Short value: " << smallValue << endl;
    cout << "Long value: " << largeValue << endl;
    cout << "Long long value: " << veryLargeValue << endl;
    cout << "Unsigned int" << count<<endl;
    cout<<"Unsigned char"<<(int)level<<endl;

    return 0;
}
