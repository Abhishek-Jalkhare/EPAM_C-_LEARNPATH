///
///
// Created by AbhishekJalkhare on 25-03-2026.
//

#include <algorithm>
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int>grades;
    cout<<(grades.empty() ? "List is empty" : "List is Non Empty")<<endl;
    grades = {12 ,34, 45 , 67 ,89,100 ,93};
    cout<<"Grades after insertion operation : "<<endl;
    ranges::for_each(grades , [](const int& x) {
        cout<<x<<" ";
    });
    cout<<endl;
    cout<<"size of list after adding grades : "<<grades.size()<<endl;

    if (!grades.empty()) {
        cout <<"First element of the list : "<< grades.front() << endl;
    }
    if (!grades.empty()) {
        cout<<"Last element of list : "<<grades.back()<<endl;
    }

    auto it = grades.begin();
    advance(it , 2); // moving iterator to position ahead form begin
    cout<<"Value at index 2 : "<<*it<<endl;
    *it = 99;
    cout<<"Value at index 2 after modification : "<<*it<<endl;


    try {
        int dist = 100;
        advance(it , dist);
       // cout<<"Accessing invalid position : "<<*it<<endl ; // this prints garbage value program may crash
    }catch (const exception& e) { // no exception is thrown , no bounds checking in lists
        cout<<"Exception Occurred "<<e.what()<<endl;
    }
    cout<<"Inserting Element at first Positon : "<<endl;
    grades.push_front(23);
    cout<<"Inserting Element before last Position : "<<endl;
    grades.insert(prev(grades.end()),99);
    cout<<"Grades after insertion  operation : "<<endl;
    ranges::for_each(grades , [](const int& x) {
        cout<<x<<" ";
    });
    cout<<endl;
    cout<<"size of list after insertion operation : "<<grades.size()<<endl;

    cout<<"Removing Last Element from list ... "<<endl;
    grades.pop_back();
    cout<<"Removing Second Element from List ... "<<endl;
    if (grades.size() >= 2) {
        grades.erase(next(grades.begin()));
    }
    cout<<"Grades after removal  operation : "<<endl;
    ranges::for_each(grades , [](const int& x) {
        cout<<x<<" ";
    });
    cout<<endl;
    cout<<"size of list after removal operation : "<<grades.size()<<endl;


    grades.clear();
    cout<<"size of list after clear operation : "<<grades.size()<<endl;
    cout<<(grades.empty() ? "Empty List" : "Non EMpty List")<<endl;

}
