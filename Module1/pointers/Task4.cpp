#include<iostream>
using namespace std;

struct Employee{
    int id;
    char name[50];
    float salary;

};

void printEmployee(const Employee* e){
    cout<<"Employee Details: "<<endl;
    cout<<"ID: "<< e->id << endl;
    cout<<"Name: "<< e->name << endl;
    cout<<"Salary: "<< e->salary << endl;
}

int main(int argc, char const *argv[])
{
    cout<<"Enter Employee details id , name and salary";
    int id  ;
    float salary;
    char name [50] ;
    cin>> id ;
    cin>> name;
    cin>>salary;
    Employee* e =new Employee();
    e->id = id;
    strcpy(e->name , name);  // use strcopy
    e->salary = salary;

    printEmployee(e);

    cout<<"Enter new Salary for employee ";
    cin>> salary;
    e->salary = salary;
    printEmployee(e);

    delete e;

    return 0;
}

