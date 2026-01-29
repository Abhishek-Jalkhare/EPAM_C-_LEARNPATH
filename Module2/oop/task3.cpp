//
// Created by AbhishekJalkhare on 29-01-2026.
//

#include "task3.h"
#include <iostream>

using namespace std;

Student::Student(const std::string& name, const int rollNo,
                 const int marks) : name(name){
    setMarks(marks);
    setRollNo(rollNo);

}

int Student::getMarks() const {
    return this->marks;
}

const std::string& Student::getName() const {
    return this->name;
}

int Student::getRollNo() const {
    return this->rollNo;
}

void Student::setMarks(int marks) {
    if (marks < 0 || marks > 100) {
        cout<<"Enter Valid marks value"<<endl;
        return;
    }
    this->marks = marks;

}


void Student::setName(const std::string& name) {
    this->name = name;
}

void Student::setRollNo(const int roll) {
    if (roll < 0) {
        cout<<"ENter a valid Roll Number"<<endl;
        return;
    }
    this->rollNo = roll;
}


int main(int argc, char* argv[]) {
    Student s("Abhishek", 12, -85);

    cout << s.getName() << endl;
    cout << s.getRollNo() << endl;
    cout << s.getMarks() << endl;

    s.setMarks(-10);
    cout << s.getMarks() << endl; // invalid marks gets message and is not applied

    s.setMarks(120);
    cout << s.getMarks() << endl;

    s.setMarks(95);
    cout << s.getMarks() << endl;

    s.setRollNo(-5);
    cout << s.getRollNo() << endl; // invalid roll gets message and is not applied

    s.setName("Rahul");
    cout << s.getName() << endl;

    // string& name = s.name  //can't be done because it is private member
    return 0;
}
