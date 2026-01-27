//
// Created by AbhishekJalkhare on 27-01-2026.
//

#include <iostream>
using namespace std;

class Student {
    int rollNo{};
    string name{};
    char grade{};
public:

    [[nodiscard]] int getRollNo() const {
        return rollNo;
    }

    void set_roll_no(int roll_no) {
        rollNo = roll_no;
    }

    [[nodiscard]] string getName() const {
        return name;
    }

    void set_name(const string &name) {
        this->name = name;
    }

    [[nodiscard]] char getGrade() const {
        return grade;
    }

    void set_grade(const char grade) {
        this->grade = grade;
    }

    Student():rollNo(0) , name("Unknown") , grade('U') {
        cout<<"Default constructor called"<<endl;
    }

    Student (const int rollNo , const string &name , const char grade):
    rollNo(rollNo) ,  name(name) ,grade(grade) {
        cout<<"Parameterized constructior called"<<endl;
    }
};

int main(int argc, char *argv[]) {
    Student s;
    cout<< s.getName()<<endl;
    Student s1 {1 , "a" , 'a'};
    cout<<s1.getName()<<endl;
}
