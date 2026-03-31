//
// Created by AbhishekJalkhare on 18-03-2026.
//
#include <iostream>
#include <memory>
// FileHandler class demonstrates RAII principle
// Resource (file) is acquired in constructor and released in destructor
class FileHandler {
public:
    // Constructor: Simulates opening a file resource
    FileHandler() {
        std::cout << "File opened."<<std::endl;
    }
    // Destructor: Automatically called when object is destroyed
    // Simulates closing the file resource
    ~FileHandler() {
        std::cout << "File closed."<<std::endl;
    }
    // Write method: Uses the message parameter
    void write(const std::string& msg) const {
        std::cout << "Writing: " << msg << std::endl;
    }

};


std::unique_ptr<FileHandler> createFileHandler() {
    return std::make_unique<FileHandler>();
}

void processFileHandler(std::unique_ptr<FileHandler> handler) {
    if (handler == nullptr) {
        std::cout << "Empty Handler Passed "<<std::endl;
        return;
    }
    //attempting to call write on nullptr would lead to runtime error
    handler->write("Message from processFileHandler.");
}

int main(int argc, char* argv[]) {
    // Step 1: Create FileHandler managed by unique_ptr
    // Ownership is with 'file' variable
    std::unique_ptr<FileHandler> file = createFileHandler();

    // Step 2: Transfer ownership to processFileHandler using std::move
    // After this call, 'file' will be nullptr (moved-from state)
    processFileHandler(std::move(file));

    // Step 3: Verify that the original pointer is now null
    // std::move transferred ownership, leaving 'file' empty
    std::cout << "After move, file pointer is: "
              << (file == nullptr ? "NULL" : "NOT NULL") << std::endl;

    // Attempting to use moved-from pointer would be undefined behavior
    // This demonstrates why we must not use pointers after moving from them
    processFileHandler(std::move(file));

}
