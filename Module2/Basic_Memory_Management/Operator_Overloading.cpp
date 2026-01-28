//
// Created by AbhishekJalkhare on 28-01-2026.
//

#include <iostream>
#include <vector>
using namespace std;

//We use a member function when the left operand must be the class object.
// We use a non-member function when the left operand is not the class object.
class Student {
public:
    string name;
    int marks;

    Student(const string &name, int marks)
        : name(name),
          marks(marks) {
    }

    bool operator==(Student s) {
        return this->name == s.name;
    }

    // void operator << (const ostream &COUT ) { in member function Student object is left operand so it will go
    // Student<<cout so it will give error so we must make operator<< non member function
    //we made the fucntion return type void which do not allow cout chaining
    //COUT<<"Name : "<<name<<endl;
    //     COUT<<"Marks : "<<marks<<endl;
    //
    // }
};

    ostream& operator<<( ostream& COUT , const Student &s   ) {
        COUT<<"Student Name : "<<s.name<<endl;
        COUT<<"Student Marks : "<<s.marks<<endl;
        return COUT;
    }


class Collection {
    public:
        vector<Student> v;
        Collection& operator+= (const Student &s ) {
            this->v.push_back(s);
            return *this;
        }



    };

int main(int argc, char *argv[]) {
    Student s1("abcd" , 12);
    Student s2("bcd" , 112);
    cout<<s1<<s2;

    cout<<(s1 == s2) << endl;
    operator<<(cout , s2 ); // refrences are bound automatically by the compiler passing &cout is wrong because the will be pointer
        // of ostream

    Collection c;
    (c += s1) += s2;


}
