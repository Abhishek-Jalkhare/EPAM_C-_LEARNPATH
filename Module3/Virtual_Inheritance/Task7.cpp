//
// Created by AbhishekJalkhare on 05-02-2026.
//

#include <iostream>
using namespace  std;

class Person {
protected:
    string name;
    explicit Person(const string& name)
        : name(name) {
    }
    Person () = default;
    virtual void displayInfo() = 0;
    virtual ~Person() = default;
};

class Student : virtual public  Person {
public:
    int rollNo ;
    Student(const string& name , int rollNo) : Person(name) , rollNo(rollNo) {
        if (rollNo < 0) {
            cout<<"Roll no can not be negative"<<endl;
            return;
        }
    }

    void displayInfo() override {
        cout<<"Student Information"<<endl;
        cout<<"Student Name : " << name << endl;
        cout<<"Studen  RollNo : "<<rollNo<<endl;
    }

};

class Employee : virtual public Person{

public:
    int salary;
    Employee(const string& name, int salary)
        : Person(name),
          salary(salary) {
        if (salary < 0) {
            cout<<"Salary can't be negative"<<endl;
            return;
        }
    }
    void displayInfo() override {
        cout<<"Employee Information"<<endl;
        cout<<"Employee Name : " << name << endl;
        cout<<"Employee  salary : "<<salary<<endl;
    }

};

class TeachingAssistant : public  Student , public Employee {
public:
    TeachingAssistant(const string& name, int rollNo, int salary)
        : Student(name, rollNo),
          Employee(name, salary) {
    }

    void displayInfo() override {
        cout<<"Teacing Assistant Info"<<endl;
        cout<<"name : " << name <<endl;
        cout<<"rollno : "<<rollNo<<endl;
        cout<<"salary : "<<salary<<endl;
  }
};


int main(int argc, char* argv[]) {
    TeachingAssistant ta{"abc" , 1, 1000} ;
    ta.displayInfo();
    std::cout <<"Address of preson subobject through Student :  "<< (Person*)(Student*)&ta << '\n';
    std::cout <<"Address of preson subobject through Employee : "<< (Person*)(Employee*)&ta << '\n';

}

