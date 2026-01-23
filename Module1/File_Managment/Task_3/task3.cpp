#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

struct Student{
    int rollNo;
    int marks;

};

void updateStudent(int roll , int marks){
    fstream file{"students.dat" , ios::in | ios::out | ios::binary };
    Student temp{};
    while(file.read(reinterpret_cast<char *>(&temp) , sizeof(Student))){
        if(temp.rollNo == roll){
            file.seekp(-(sizeof(Student)) , ios::cur);
            
            temp.marks = marks;
            file.write((char*)&temp , sizeof(Student));
            file.close();
            cout<<"Updation successfull" <<endl;
        }
    }
    cout<<"no record found"<<endl;
    
    file.close();
}

void addStudent( Student * s){
    fstream filereader{"students.dat" , ios::in | ios::binary};
    Student temp;
    while( filereader.read((char *)&temp , sizeof(Student)) ){
        if( s->rollNo == temp.rollNo ){
            cout<<"student already exist"<<endl;
            return;
        }
    }

    fstream filewriter{"students.dat" , ios::binary|ios::app};
    filewriter.write((char *)s , sizeof(Student));

    filereader.close();
    filewriter.close();
}


void createFile(  ){
    ofstream writer{"students.dat"};
    writer.close();
}

void displayAllStudent(){
    cout<<endl<<endl;
    ifstream file("students.dat" , ios::binary | ios::in);
    cout<<"Roll number "<<setw(20) <<"Marks"<<endl;
    cout<<string(30 , '-')<<endl;
    Student e;
    while(file.read((char *)&e , sizeof(Student)))
        cout<<e.rollNo<<setw(20) <<e.marks<<endl;
    file.close();
}


int main(int argc, char const *argv[])
{
    createFile();
    Student* s1 = new Student{1 , 99};    
    Student* s2 = new Student{2 , 93};
    addStudent(s1);    
    addStudent(s2);
    displayAllStudent();

    updateStudent(1,0);
    displayAllStudent();
    
    return 0;
}
