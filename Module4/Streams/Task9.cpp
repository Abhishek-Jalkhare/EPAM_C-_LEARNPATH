//
// Created by AbhishekJalkhare on 12-02-2026.
//
#include <chrono>
#include <iostream>
#include <thread>
#include <fstream>
using namespace std;

class Logger {
    ofstream ofs;
public:
    explicit Logger(const string& fileName):ofs{fileName , ios::app} {
        if (!ofs.is_open()) {
            throw runtime_error("File can not be opened");
        }
    }

    void log(const string& message ) {
        const auto now = std::chrono::system_clock::now();
        const std::time_t t = std::chrono::system_clock::to_time_t(now);
        const auto time_stamp = put_time(localtime(&t),"%Y-%m-%d %H:%M:%S" );

        ofs<<message << "   ,  "<<time_stamp<<endl;
    }

    ~Logger() {
        ofs.close();
    }


};

int main(int argc, char* argv[]) {
    Logger logger{"Task9_LoggerFile"};
    logger.log("message1");
    logger.log("message1");
    logger.log("message1");
    std::this_thread::sleep_for(std::chrono::seconds(5));//pausing program for 5 second
    logger.log("message1");


}
