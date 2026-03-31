//
// Created by AbhishekJalkhare on 13-03-2026.
//
#include <iostream>
#include <chrono>

class Timer {
    std::chrono::high_resolution_clock::time_point start;
    std::string label;
public:
    Timer(const std::string& lbl = "") : start(std::chrono::high_resolution_clock::now()), label(lbl) {
        if (!label.empty()) std::cout << "Timer started: " << label << std::endl;
    }
    ~Timer() {
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << (label.empty() ? "Elapsed time: " : "Timer [" + label + "] elapsed: ");
        std::cout << duration.count() << "us" << std::endl;
    }
};

int main(int argc, char* argv[]) {
    Timer t("Loop Blocking Timer ");
    int sum = 0;
    for (int i = 0 ; i< 100000000;i++) {
        sum += i;
    }
    // timer is destroyed here
}
