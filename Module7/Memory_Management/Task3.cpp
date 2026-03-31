//
// Created by AbhishekJalkhare on 18-03-2026.
//
#include <iostream>
#include <memory>
class SensorReport {
    int value;
    std::string sensorName;

public:
    SensorReport(const int value, const std::string& sensor_name)
        : value(value),
          sensorName(sensor_name) {
        std::cout << "SensorReport for "<<sensor_name<<" created."<<std::endl;
    }

    void displayDetails() const{
        std::cout << "Sensor Name : "<<sensorName<<", Value : "<<value<<std::endl;
    }

    ~SensorReport() {
        std::cout <<"SensorReport for "<<sensorName<<" destroyed.";
    }

};

int main(int argc, char* argv[]) {
    int rawSensorValue = 75;
    std::string sensorIdentifier = "Pressure_A01";

    std::unique_ptr<SensorReport> criticalReportPtr = std::make_unique<SensorReport>
    (rawSensorValue , sensorIdentifier);

    std::cout << "\nProcessing critical sensor report:" << std::endl;
    criticalReportPtr->displayDetails();

    //std::unique_ptr<SensorReport> anotherReport = criticalReportPtr;
    // this will cause compile error  : Attempt to use deleted constructor

    std::cout << "Program Execution Completed "<<std::endl;
}

