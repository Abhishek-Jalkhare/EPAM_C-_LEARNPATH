//
// Created by AbhishekJalkhare on 25-03-2026.
//
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[]) {
    std::list<std::string> Warehouse1 = {"A100", "A200", "A300"};
    std::list<std::string> Warehouse2 = {"A150", "A250", "A350"};
    if (Warehouse1.empty()) {
        cout<<"Warehouse1 List empty : can't process";
        return 1;
    }
    Warehouse1.sort();
    cout<<"WareHouse 1 sorted list : ";
    ranges::for_each(Warehouse1,[](const string& x) {
        cout<<x<<" ";
    });
    cout<<endl;
    if (Warehouse2.empty()) {
        cout<<"Warehouse2 EMpty can't proccess ";
        return 1;
    }
    Warehouse2.sort();
    cout<<"WareHouse 2 sorted list : ";
    ranges::for_each(Warehouse2,[](const string& x) {
        cout<<x<<" ";
    });
    cout<<endl;

    cout<<"Merging Warehouse1 and Warehouse2 lists.... "<<endl;
    Warehouse1.merge(Warehouse2); // this will wokr becuse list1 and list2 is sorted
    cout<<"Merged WareHouse 1 and Warehouse 2 sorted list : ";
    ranges::for_each(Warehouse1,[](const string& x) {
        cout<<x<<" ";
    });
    cout<<endl;
    if (Warehouse2.empty()) {
        cout << "Warehouse2 is now empty after merge." << endl;
    } else {
        cout << "Warehouse2 size: " << Warehouse2.size() << endl;
    }

}

