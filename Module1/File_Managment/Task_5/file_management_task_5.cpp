#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;

struct Employee{
    int id ;
    char name [50];
};

void addEmployee ( Employee * e   ){
    fstream filewriter ("employee.dat" , ios::binary | ios::app); // if we we use in (reader operator) we can not create file
    //if not present
    fstream filereader ("employee.dat" ,   ios::binary | ios::in  ); // WE CAN NOT SAME FILE READER 
    // TO READ AND APPEND BECAUSE THEY BOTH PONT TO DIFFRENT LOCATION AND CAUSE UNEXPECTED BEHAVIOUR
    //Don’t use ios::app if you need to read before writing
// ✅ Clear stream state after read: file.clear()
// ✅ Reposition pointer before write: seekp()
// ✅ Binary files → always use read() / write()
    

    if(!filereader.is_open()) {
        cout<<"File can't be opened" <<endl;
        return;
    }
    Employee emp;
    while(filereader.read((char *)&emp , sizeof(Employee))){
        if(emp.id == e->id){
            cout<<"Employee with id "<<e->id <<" already exist"<<endl;
            return;
        }
    }
    filereader.close();
    filewriter.write((char *)e ,sizeof(Employee));
    filewriter.close();
}

void showAllEmployees (){
    ifstream file("employee.dat" , ios::binary | ios::in);
    cout<<"id"<<setw(20) <<"name"<<endl;
    cout<<string(30 , '-')<<endl;
    Employee e;
    while(file.read((char *)&e , sizeof(Employee)))
        cout<<e.id<<setw(20) <<e.name<<endl;
}


void deleteEmployee(int id){
    fstream filereader ("employee.dat" ,  ios::binary | ios::in |ios::out);
    fstream filewriter ("temp.dat" , ios::binary | ios::out);
    Employee emp;
    while(filereader.read((char *)&emp , sizeof(Employee))){
        if( emp.id != id){
            filewriter.write((char*)&emp , sizeof(Employee ));
           // return;
        }
    }
    
    filereader.close();
    filewriter.close();
    remove("employee.dat");
    rename("temp.dat" , "employee.dat");

    return;


}



int main(int argc, char const *argv[])
{
    Employee* e1 = new Employee {1 , "abhishek"};
    Employee* e2 = new Employee {2 , "abhishek"};
    addEmployee(e1);
    addEmployee(e2);
   
    deleteEmployee(1);
    showAllEmployees();
    return 0;
}
