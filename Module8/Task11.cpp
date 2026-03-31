#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void removeStudents(set<int>&students , int id) {
    cout<<"Initial size :"<<students.size()<<endl;
    auto i = students.erase(id);
    if (i == 0) {
        cout<<"No element Removed "<<endl;
    }
    else {
        cout<<"Element removed Successfully "<<endl;
    }
    cout<<"size after removal operation : "<<students.size()<<endl;

}

void checkStudentExistence(const set<int>&students , int id) {
    if (students.find(id) != students.end()) cout<<"Student with Id : "<<id<<" found"<<endl;
    else cout<<"No such student exist"<<endl;
}

void populateAndDemonstrateUniqueness(set<int>&student , initializer_list<int> studentIDs) {
    for (auto i : studentIDs) {
        student.insert(i);
    }
    cout<<"size before inserting duplicate ele "<<student.size()<<endl;
    student.insert(*(studentIDs.end()-1)); // inserting duplicate last element
    cout<<"size after inserting duplicate ele "<<student.size()<<endl;
}

void printRoster(const set<int>&students , const string& title) {
    cout<<"==="<<title<<"==="<<endl;
    for (auto i : students) {
        cout<<"Student Id : "<<i<<endl;
    }
}

int main(int argc, char* argv[]) {
    set<int>students;
    cout<<"Set studentID declared ."<<endl;
    populateAndDemonstrateUniqueness(students, {101, 105, 103, 102});
    printRoster(students, "Student IDs in the set (initial roster):");
    std::cout << "--- Step 4: Checking for Student Existence ---\n";
    checkStudentExistence(students, 103); // Check for an existing ID checkStudentExistence(studentIDs, 999);
    checkStudentExistence(students,9999);// Check for a non-existent ID std::cout << "\n";
    cout<<"----Removing Students----"<<endl;
    removeStudents(students,105);//removing existing elements
    removeStudents(students,122);//removing non-existing elements
    printRoster(students, "Final Student IDs in the set:");



}
