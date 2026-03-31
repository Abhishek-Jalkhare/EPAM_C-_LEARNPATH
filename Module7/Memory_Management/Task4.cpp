//
// Created by AbhishekJalkhare on 18-03-2026.
//
#include <iostream>
#include <memory>

class LogMessage {
    std::string message_content;

public:
    explicit LogMessage(const std::string& message_content)
        : message_content(message_content) {
        std::cout<< "LogMessage '" << message_content <<
            "' created. Address: " << this << std::endl;
    }
    ~LogMessage() {
        std::cout << "LogMessage '" << message_content <<
            "' destroyed. Address: " << this << std::endl;
    }

    void printContent() const{
        std::cout<<"Message Content : "<<message_content<<std::endl;
    }
};

void handleLegacy(LogMessage* rawMessage) {
    if (rawMessage == nullptr){
        std::cout << "Legacy system received a nullptr log.\n";
        return;
    }

    std::cout <<  "Legacy system is now handling log: ";
    rawMessage->printContent();
    delete rawMessage;
    rawMessage = nullptr;

}

int main(int argc, char* argv[]) {
    std::unique_ptr<LogMessage> myLog = std::make_unique<LogMessage>("System Startup Event");
    std::cout << "Unique ptr is created \n it's intial state : ";
    myLog->printContent();

    LogMessage* handedOverLog = myLog.release();
    std::cout << "My Log Has Released Ownership "<<std::endl;

    handleLegacy(handedOverLog);
    if (!myLog) {
        std::cout << "myLog unique_ptr is now empty (nullptr) after release().\n";
    }
    else {
        std::cout << "Error: myLog unique_ptr is NOT empty after release()!\n";
    }
}
