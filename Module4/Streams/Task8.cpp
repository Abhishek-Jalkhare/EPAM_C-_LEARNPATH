//
// Created by AbhishekJalkhare on 12-02-2026.
//
#include <iostream>

using namespace std;

class Person {
    string name;
    int age{};
public:
    Person(const string& name , const int age): name(name) , age(age) {
    }

    Person() = default;

    friend istream& operator>>(istream& CIN,  Person&p );
    friend ostream& operator<<(ostream& COUT ,const Person&p);

};

istream& operator>>(istream& CIN ,  Person& p) {
    cout<<"Enter Person Name : "<<endl;
    getline(CIN ,p.name);
    CIN.ignore();
    cout<<"Enter person age : "<<endl;
    CIN>>p.age;
    return CIN;
}

ostream& operator<<(ostream& COUT ,const Person& p) {
    COUT<<"Person Name : "<<p.name<<endl<<"person age : "<<p.age<<endl;
    return COUT;
}




int main(int argc, char* argv[]) {
    Person p1 , p2 , p3 , p4;
    cin>>p1>>p2>>p3>>p4;
    cout<<p1 <<p2 <<p3 <<p4;



}
