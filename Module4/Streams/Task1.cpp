//
// Created by AbhishekJalkhare on 09-02-2026.
//
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    string name , city;
    int age;
    cout<<"Enter Your Name : ";
    getline(cin ,name);
    cout<<"\nEnter your age : ";
    cin>>age;
    cin.ignore();
    cout<<"\nEnter your city : ";
    getline(cin, city);

    cout<<"\n Hello "<<name<<", you are "<<age <<" and live in "<<city<<".";



}
