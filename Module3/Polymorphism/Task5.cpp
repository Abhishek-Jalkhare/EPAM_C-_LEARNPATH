//
// Created by AbhishekJalkhare on 03-02-2026.
//
//
// Created by AbhishekJalkhare on 02-02-2026.
//
#include <iostream>
#include <vector>
using namespace std;
//Defines a base class Employee with private members name (std::string),
//id (int) Provides accessors and mutators for private members
//(with validation if needed) Declares a pure virtual function calculatePay()
//in the Employee class, making it abstract Derives SalariedEmployee (e.g., salary)
//and HourlyEmployee (hourlyRate, hoursWorked) classes, each overriding calculatePay()
//with their own logic Stores different employees in a container (e.g., std::vector<Employee*>)
//Calculates and displays pay for each employee polymorphically through the base pointer

class Employee {
    string name;
    int id;

public:
    Employee(const string& name, int id)
        : name(name),
          id(id) {
    }

    [[nodiscard]] string getName() const {
        return name;
    }

    void setName(const string& name) {
        if (name.empty()) {
            cout<<"Name can't be empty"<<endl;
            return;
        }
        this->name = name;
    }

    [[nodiscard]] int getId() const {
        return id;
    }

    void setId(const int id) {
        if (id < 0) {
            cout<<"Id can not be negative "<<endl;
        }
        this->id = id;
    }

    [[nodiscard]] virtual  double calculatePay() const = 0;
    virtual ~Employee() = default;
};

class SalariedEmployee : public Employee {
    double salary;

public:
    [[nodiscard]] double getSalary() const {
        return salary;
    }

    void setSalary(const double salary) {
        if (salary <= 0) {
            cout<<"Salary can not be less than 0"<<endl;
            return;
        }
        this->salary = salary;
    }

    SalariedEmployee(const string& name ,int id ,double salary)
        : Employee(name , id){
        setSalary(salary);
    }

    [[nodiscard]] double calculatePay() const override  {
        return salary;
    }
};

class HourlyEmployee : public Employee{
    int hourlyRate;
    int hoursWorked;

public:
    HourlyEmployee(const string& name, int id, double hourly_rate, double hours_worked)
        : Employee(name, id){
        setHourlyRate(hourly_rate);
        setHoursWorked(hours_worked);
    }

    [[nodiscard]] double getHourlyRate() const {
        return hourlyRate;
    }

    void setHourlyRate(const double hourly_rate) {
        if (hourly_rate < 0) {
            cout<<"rate can't be negative"<<endl;
            return;
        }
        hourlyRate = hourly_rate;
    }

    [[nodiscard]] double getHoursWorked() const {
        return hoursWorked;
    }

    void setHoursWorked(const double hours_worked) {
        if (hours_worked < 0) {
            cout<<"Hours can't be negative"<<endl;
        }
        hoursWorked = hours_worked;
    }
    double calculatePay() const override {
        return hourlyRate * hoursWorked;
    }

};

int main(int argc, char* argv[]) {
    vector<Employee*> emp = {
        new SalariedEmployee("abc" , 12 , 4564) ,
        new HourlyEmployee("def" , 11, 5000 , 40)
    };

    for (Employee * e : emp) {
        cout<<"---Employeee----"<<endl
        <<"Name : "<<e->getName()<<endl
        <<"salary : "<<e->calculatePay()<<endl;
    }
}
