//
// Created by AbhishekJalkhare on 11-02-2026.
//
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]) {
    cout<<"Enter File content"<<endl;
    ofstream ofs("Task7_Input_File.txt");
    string line;
    getline(cin , line);
    ofs<<line<<endl;

    ifstream ifs("Task7_Input_File.txt");
    if (!ifs.is_open()) {
        cout<<"can't open file"<<endl;
        return 1;
    }
    int value;
    while (true) {
        ifs>>value;
        if (ifs.bad()) {
            cout<<"Serious error encounterd"<<endl;
            return 1;
        }
        if (ifs.fail()) {
            if (ifs.eof()) {
                cout<<"End of file reached"<<endl;
                break;
            }
            ifs.clear(); // invalid character encountered
            ifs.ignore();
        }

        else cout<<value<< " , ";



    }
}
