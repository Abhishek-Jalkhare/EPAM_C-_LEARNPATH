//
// Created by AbhishekJalkhare on 29-01-2026.
//
// Defines a base class Person with data members: name (std::string) and
// age (int) Derives a Student class that adds rollNo (int) and grade (char)
// Derives a Teacher class that adds subject (std::string) and salary (double)
// Demonstrates how derived classes use base class members (e.g.,
// setting and displaying name and age for Student/Teacher objects)
//

#include <iostream>
#include <ranges>
#include <stdexcept>
using namespace std;

class Person {
    string name;
    int age{};
protected:
    Person(const string & name , const int age) {
        setName(name);
        setAge(age);
    }

public:
    [[nodiscard]] string getName() const {
        return this->name;
    }

    void setName(const string & name) {
        if (name.empty()) {
            throw std::invalid_argument("Name is empty");


        }
        this-> name = name;
    }

    [[nodiscard]] int getAge() const {
        return  this->age;
    }

    void setAge(const int age) {
        if ( age < 0) {
            throw std::invalid_argument("age can't be negative");
        }
        this-> age = age;
    }

    virtual void display()const = 0;
    virtual ~Person() = default;
};

class Student : public Person {
    int roLLNo ;
    char grade ;

public:
    Student(const string& name ,const int age ,const int rollNo ,const char grade) : Person(name ,age) {
        setRollNo(rollNo);
        setGrade(grade);
    }

    void setRollNo (int rollNo) {
        if (rollNo <= 0) {
            throw std::invalid_argument("RollNo can't be negative");
        }
        this->roLLNo = rollNo;
    }

    [[nodiscard]] int getRollNo() const {
        return this->roLLNo;
    }

    void setGrade(char grade) {
        if (!(grade == 'A' || grade == 'B' || grade == 'C' || grade == 'D' || grade == 'E' || grade == 'F' )) {
            throw std::invalid_argument("Invalid value for grade");
        }
        this->grade = grade;
    }

    [[nodiscard]] char getGrade() const {
        return  this->grade;
    }
    void display()const override {
        cout<<"Student name : "<<this->getName()<<endl;
        cout<<"Student age : "<<this->getAge()<<endl;
        cout<<"Student Grade : "<<this->getGrade()<<endl;
        cout<<"Student RollNo : "<<this->getRollNo()<<endl;
    }


};

class Teacher : public Person{
    string subject;
    double salary;
public:
    Teacher(const string& name , int age , const string& subject , double salary):
            Person(name, age) {
        setSalary(salary);
        setSubject(subject);
    }
    void setSubject(const string& subject) {
        if (subject.empty()) {
            throw std::invalid_argument("subject can not be empty");
        }
        this->subject = subject;
    }
    [[nodiscard]] string getSubject() const {
        return this->subject;
    }
    void setSalary(double salary) {
        if (salary <= 0) {
            throw std::invalid_argument("salary can't be negative");
        }
        this->salary = salary;
    }
    [[nodiscard]] double getSalary() const {
        return this->salary;
    }
    void display() const override  {
        cout<<"Teacher name : "<<this->getName()<<endl;
        cout<<"Teacher age : "<<this->getAge()<<endl;
        cout<<"Teacher subject : "<<this->getSubject()<<endl;
        cout<<"Teacher salary : "<<this->getSalary()<<endl;
    }
};

ostream& operator<<( ostream& os , const Teacher& t ) {
    os<<"Teacher name : "<<t.getName()<<endl;
    os<<"Teacher age : "<<t.getAge()<<endl;
    os<<"Teacher subject : "<<t.getSubject()<<endl;
    os<<"Teacher salary : "<<t.getSalary()<<endl;

    return os;
}
ostream& operator<<( ostream& os , const Person& t ) {
    os<<"Teacher name : "<<t.getName()<<endl;
    os<<"Teacher age : "<<t.getAge()<<endl;
   // os<<"Teacher subject : "<<t.getSubject()<<endl;
    //os<<"Teacher salary : "<<t.getSalary()<<endl;

    return os;
}
ostream& operator<<( ostream& os , const Student& t ) {
    os<<"Teacher name : "<<t.getName()<<endl;
    os<<"Teacher age : "<<t.getAge()<<endl;
    os<<"Teacher subject : "<<t.getRollNo()<<endl;
    os<<"Teacher salary : "<<t.getGrade()<<endl;

    return os;
}

//operator overloading is resolved at compile time so whatever type of object is provide
// it's respective implementation runs
//so use method overriding display method when utilizing polymorphic behavior


int main(int argc, char* argv[]) {
    const Student s("Abhishek", 20, 101, 'A');
    cout << "Student Details\n";
    cout << "Name: " << s.getName() << "\n";
    cout << "Age: " << s.getAge() << "\n";
    cout << "Roll No: " << s.getRollNo() << "\n";
    cout << "Grade: " << s.getGrade() << "\n\n";

    const Teacher t("Rahul", 45, "Mathematics", 55000.75);

    cout << "Teacher Details\n"<<t;

    // cout << "Name: " << t.getName() << "\n";
    // cout << "Age: " << t.getAge() << "\n";
    // cout << "Subject: " << t.getSubject() << "\n";
    // cout << "Salary: " << t.getSalary() << "\n\n";


    const Person* p1 = new Student("Neha", 19, 202, 'B');
    const Person* p2 = new Teacher("Suresh", 50, "Physics", 72000.50);
    // if we make p1 const then p1 can only call const method of Person class;


    cout << "Polymorphic Access\n";
    p1->display();
    p2->display();



    delete p1;
    delete p2;
}
