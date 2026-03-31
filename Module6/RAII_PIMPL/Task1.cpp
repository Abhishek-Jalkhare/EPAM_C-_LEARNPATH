//
// Created by AbhishekJalkhare on 13-03-2026.
//
#include <iostream>
#include <fstream>
using namespace std;

class FileWrapper {
    ofstream file;
public:
    explicit FileWrapper(const string& file)  {
        this->file.open(file);
        if (!this->file) throw runtime_error("can't open file");
        cout<<"File opened"<<endl;
    }

    ~FileWrapper() {
        if (this->file.is_open()) {
            this->file.close();
        }
        cout<<"File closed"<<endl;
    }

    ofstream& get() {
        return file;
    }
};

int main(int argc, char* argv[]) {
    try {
        FileWrapper file("a.txt");
        file.get()<<"line 1 content"<<endl ;
        file.get()<<"Line 2 content"<<endl;
        // Uncomment the following to test exception safety:
        // throw std::runtime_error("Simulated crash!");
    }catch (exception& e) {
        cout<<"Exception occured : "<<e.what()<<endl;
    }
    std::cout << "Back in main, after FileWrapper goes out of scope.\n";
}
