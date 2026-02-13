//
// Created by AbhishekJalkhare on 10-02-2026.
//
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]) {
    string input_file = "Task4_input_file.txt";
    string output_file = "Task4_output_file.txt";

    ifstream file_reader(input_file);
    if (!file_reader.is_open()) {
        cout<<"can't open source file "<<endl;
        return 1;
    }

    ofstream file_writer{output_file};
    if (!file_writer.is_open()) {
        cout<<"can open destination file"<<endl;
        return 1;
    }
    string line;
    while (getline(file_reader ,line)) {
        file_writer<<line<<endl;
    }
    file_reader.close();
    file_writer.close();
}
