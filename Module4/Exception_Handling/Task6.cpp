//
// Created by AbhishekJalkhare on 17-02-2026.
//
#include <iostream>
using namespace std;

class  MedicalMemoryTracker {
public:
    inline static int totalMemAllocate = 0;
    inline static int totalMemDeallocated = 0;
    static void recordAllocation(const char* medicalResource, int size) {
        totalMemAllocate += size;
        cout<<"Memory allocated for "<<medicalResource<<" of size : "<<size<<endl;
    }

    static void recordDeallocation(const char* medicalResource, int size) {
        totalMemDeallocated += size;
        cout<<"Memory deallocated for "<<medicalResource<<" of size : "<<size<<endl;
    }

    static void reportLeaks() {
        if (totalMemAllocate == totalMemDeallocated) cout<<"No memo leak"<<endl;
        else cout<<"Memory Leak : TotalMemoAllocated = "
        <<totalMemAllocate<< ", Total memo Deallocated = "<<totalMemDeallocated<<endl;
    }

    static void reset() {
        totalMemAllocate = 0;
        totalMemDeallocated = 0;
    }

};

class MedicalDeviceException : public runtime_error {
public:
    explicit MedicalDeviceException(const string& msg):runtime_error(msg){}
};

class PatientDataException : public runtime_error {
public:
    explicit  PatientDataException(const string& msg):runtime_error(msg){}
};

class PatientVitalMonitor {
    int *heartRateData  ;
    float* bloodPressureData ;
    bool deviceConnected ;
    const char *patientId ;

public:
    PatientVitalMonitor(const char * id): heartRateData(nullptr) , bloodPressureData(nullptr),
        deviceConnected(false) , patientId(id) {
        heartRateData = new int[36000];
        MedicalMemoryTracker::recordAllocation("Heart Rate Buffer", 36000 * sizeof(int));
        bloodPressureData = new float[18000];
        MedicalMemoryTracker::recordAllocation("Blood Pressure Buffer", 18000 * sizeof(float));
    }

    void connectToMedicalDevice() {
        if (rand()%2 == 0) {
            throw MedicalDeviceException("Can not connect to medical device");
        }
    }

    void calibrateSensors() {
        if (rand()%2 == 0) {
            throw MedicalDeviceException("Calibration error in sensors");
        }
    }

    void validatePatientData() {
        int a = rand();
        if (a % 2 == 0) {
            throw PatientDataException("Invalid Patient Data");
        }
    }

    void analyzeCriticalTrend() {
        if (rand() % 2 == 0) {
            throw PatientDataException("Can't analyse Critical data ");
        }
    }

    void monitorPatientVitals(const int durationMinutes) {

        while (true) {
            if (durationMinutes <= 0){
                throw std::invalid_argument("E001: Monitoring duration must be positive!");
            }

            float* ecgAnalysisBuffer = new float[5000];
            MedicalMemoryTracker::recordAllocation("ecg Analysis buffer", sizeof(float)*5000);
            validatePatientData();
            int * criticalTrendBuffer = new int[1000];
            MedicalMemoryTracker::recordAllocation("Critical Trend Buffer", sizeof(int)*1000);

            delete[] ecgAnalysisBuffer;
            MedicalMemoryTracker::recordDeallocation("ECG Analysis Buffer", 5000 * sizeof(float));
            std::cout << " ECG analysis completed - buffer freed" << std::endl;

            delete[] criticalTrendBuffer;
            MedicalMemoryTracker::recordDeallocation("Critical Trend Buffer", 5000 * sizeof(float));
            std::cout << " Critical trend analysis completed - buffer freed" << std::endl;
        }
    }





    ~PatientVitalMonitor() {
        cout<<"PatientVitalMonitor Object Destroyed"<<endl;
        if (heartRateData != nullptr) {
            MedicalMemoryTracker::recordDeallocation("Heart Rate Buffer", 36000 * sizeof(int));
            delete[] heartRateData;
        }
        if (bloodPressureData != nullptr) {
            MedicalMemoryTracker::recordDeallocation("Blood Pressure Buffer", 18000 * sizeof(float));
            delete[] bloodPressureData;
        }

    }

};

int main(int argc, char* argv[]) {
    cout<<"medical patient monitoring system that demonstrates real-world memory leaks caused \n"
          " by stack unwinding during exception handling"<<endl;

    srand(static_cast<unsigned>(time(nullptr)));
    cout<<"Enter number of attempts between (5 - 10) "<<endl;
    int attempts;
    cin>>attempts;
    MedicalMemoryTracker::reset();
    PatientVitalMonitor *  emergencyMonitor = nullptr;
    bool setUpSuccessful = false;
    for (int i = 0 ; i < attempts ; i++){
        try {
            emergencyMonitor = new PatientVitalMonitor {"EMERGENCY-001"};
            setUpSuccessful = true;
            if (setUpSuccessful) {
                cout<<"set up succesfull"<<endl;
            }

        }catch (const MedicalDeviceException& e) {
            cout<<"Medical Device Exception : "<<e.what()<<endl;
        }

        try {
            if (setUpSuccessful && emergencyMonitor) {
                emergencyMonitor->monitorPatientVitals(10);
            }
        }
        catch (const PatientDataException& e) {
            cout<<e.what()<<endl;
        }

        delete emergencyMonitor;
        MedicalMemoryTracker::reportLeaks();
    }

}
