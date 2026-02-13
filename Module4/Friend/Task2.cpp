//
// Created by AbhishekJalkhare on 12-02-2026.
//
#include <iostream>
using namespace std;

class Result;
class Student {
    string name;
    int marks;

public:
    Student(const string& name, const int marks)
        : name(name),
          marks(marks) {
    }
    friend class Result;
};

class Result {
public:
    void display(const Student& s) const {
      cout<<"Student name : "<<s.name<<endl;
      cout<<"Result : "<< (s.marks > 33 ? "Pass" : "Fail")<<endl;
  }
};

int main(int argc, char* argv[]) {
    Student s("Alice", 72);
    Student s1{"Bob" , 3};

    const Result r;
    r.display(s);
    r.display(s1);

}
