//
// Created by AbhishekJalkhare on 25-03-2026.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    vector<string>students{ "Alice", "Bob", "Charlie", "Diana", "Eve"};
    cout<<"Printing List of students ..."<<endl;
    ranges::for_each(students , [](const string& x) {
        cout<<x<<" ";
    });
    cout<<endl;
    cout<<"Removing charlie form student"<<endl;
    if (!students.empty()) {
        students.erase(ranges::remove(students, "Charlie").begin(), students.end());
    }
    cout<<"Printing List of students ..."<<endl;
    ranges::for_each(students , [](const string& x) {
        cout<<x<<" ";
    });
    cout<<endl;
    auto res = ranges::find(students, "Eve");
    cout<<(res != students.end() ? "Eve found at : "+to_string(distance(students.begin(),res)):
        "Eve Not Found");
    cout<<endl;
    cout<<"Sorting List Of Students.... "<<endl;
    ranges::sort(students);
    cout<<"Printing List of students ..."<<endl;
    ranges::for_each(students , [](const string& x) {
        cout<<x<<" ";
    });

    cout<<endl;
    students.clear();
    cout<<"size of list after clear operation : "<<students.size()<<endl;
    cout<<(students.empty() ? "Empty List" : "Non Empty List")<<endl;

}

