//
// Created by AbhishekJalkhare on 10-02-2026.
//
#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    cout<<"Enter The File Name"<<endl;
    string file_name;
    cin>>file_name;
    ofstream file_writer(file_name+".txt");

    if (!file_writer.is_open()) {
        cout<<"File is not open"<<endl;
        return 1;
    }

    cout<<"Enter text to write in a file : " <<endl;
    string text;
    cin.ignore();
    getline(cin , text);
    file_writer<<text;

    file_writer.close();
    ifstream file_reader(file_name+".txt");
    if (!file_reader.is_open()) {
        cout<<"File cant be opened";
        return 1;
    }
    string line;
    while (getline(file_reader , line)) {
        cout<<line<<endl;
    }
    file_reader.close();


}
