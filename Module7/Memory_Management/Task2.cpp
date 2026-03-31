//
// Created by AbhishekJalkhare on 18-03-2026.
//
#include <iostream>
#include <memory>


class Logger {
    std::string name;
    bool isActive;
public:
    explicit Logger(const std::string& name) : name(name), isActive(true) {
        std::cout << "Logger '" << name << "' created.\n";
    }

    void log(const std::string& msg) const{
        if (!isActive) return; // Don't log if closed
        std::cout << "[" << name << "]: " << msg << "\n";
    }

    void close() {
        // Prevents logging after logger has been closed
        if (!isActive) return;
        isActive = false;
        std::cout << "Logger '" << name << "' closing.\n";
    }

    [[nodiscard]] const std::string& getName() const{
        return this->name;
    }

    ~Logger() {
        close();
        std::cout << "Logger '" << name << "' destroyed.\n";
    }
};



int main() {
    std::unique_ptr<Logger> logger = std::make_unique<Logger>("Main Logger");
    logger->log("Hello from main Logger");
    logger = std::make_unique<Logger>("SecondaryLogger");//move assingment operation
    logger->log("Hello From Secondary Logger");
    logger.reset(new Logger("Temporary Logger"));
    logger->log("I replaced the previous logger");
    logger.reset();
    std::cout << "Logger is now " << (logger ? "not null" : "nullptr") << "\n";


    logger = nullptr;
    logger = std::make_unique<Logger>("NewLogger");
    logger->log("Back in business");
    auto logger2 = std::make_unique<Logger>("Logger2");
    logger = std::move(logger2);
    logger->log("Now I own Logger2's resource");
    std::cout << "logger2 is " << (logger2 ? "not null" : "nullptr") << "\n";


    logger = std::move(logger); // Self-assignment
    logger->log("Self-move didn't destroy me!");
}
