#include <iostream>
using namespace std;

class Car {
    bool engineOn;
    int speed;
    int rpm;

public:
    Car() : engineOn(false), speed(0), rpm(0) {}

    void start() {
        engineOn = true;
        cout << "Engine started\n";
        displayState();
    }

    void accelerate() {
        if (!engineOn) {
            cout << "Cannot accelerate: engine is off\n";
            return;
        }
        speed += 20;
        rpm += 1000;
        cout << "Car accelerated\n";
        displayState();
    }

    void brake() {
        if (speed > 0) {
            speed -= 20;
            if (speed < 0) speed = 0;
        }
        if (rpm > 0) {
            rpm -= 1000;
            if (rpm < 0) rpm = 0;
        }
        cout << "Brake applied\n";
        displayState();
    }

    void displayState() const {
        cout << "Engine: " << (engineOn ? "ON" : "OFF") << "\n";
        cout << "Speed: " << speed << "\n";
        cout << "RPM: " << rpm << "\n\n";
    }
};

int main(int argc, char* argv[]) {
    Car c;
    c.accelerate();
    c.start();
    c.accelerate();
    c.brake();
    c.brake();
    return 0;
}
