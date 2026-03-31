//
// Created by AbhishekJalkhare on 25-03-2026.
//
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

struct Task {
    std::string name;
    int priority;
    int deadline;

    void print() const {
        cout<<"Task Detail :"<<endl;
        cout<<"Name : "<<name<<endl;
        cout<<"Priority : "<<priority<<endl;
        cout<<"Deadline : "<<deadline<<endl;
    }


};

void print(const list<Task>& tasks) {
    cout<<"Printing List ..."<<endl;
    ranges::for_each(tasks , [](const Task& x) {
       x.print();
   });
}

int main( ) {
    list<Task> tasks = { {"Sending the Mail", 2, 5},
        {"Fix Critical bug", 1, 1},
        {"Team meeting", 2, 1},
        {"Code review", 2, 3},
        {"Update docs", 3, 4}
    };
    if (tasks.empty()) {
        cout<<"List is Empty ."<<endl;
        return 1;
    }
    print(tasks);
    tasks.sort([](const Task& t1 ,const Task& t2 ) {
        if (t1.priority != t2.priority) return t1.priority < t2.priority;
        else return  t1.deadline<t2.deadline;
    });

    print(tasks);
}
