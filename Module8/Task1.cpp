//
// Created by AbhishekJalkhare on 24-03-2026.
//
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    vector<int>grades;
    cout<<__cplusplus<<endl;
    cout<<"Size of Empty Vector : "<<grades.size()<<endl;

    grades.push_back(80);
    grades.push_back(90);
    grades.push_back(30);
    grades.push_back(40);
    grades.push_back(50);
    grades.push_back(10);

    cout<<"Printing All grades Using range Based Loop : "<<endl;
    for (auto i : grades) {
        cout<<i <<" ";
    }
    cout<<endl;
    cout<<"Size of Current Vector : "<<grades.size()<<endl;

    //accessing and Modifying grades
    cout<<"First element (using front()) : "<< grades.front()<<endl;

    cout<<"Last Element (using back()) : "<<grades.back()<<endl;

    cout<<"Accessing grade at index 2 using [] operator : "<<grades[2]<<endl;
    cout<<"Accessing grade at index 2 using at() method : "<<grades.at(2)<<endl;

    // modifying grade at index 2
    grades[2] = 90;
    cout<<"Modified value at index 2 : "<<grades[2]<<endl;
    try {
        int invalid_val = grades.at(9);
    }
    catch (const out_of_range& e) {
        cout<<"Out of Range error encountered : "<<e.what()<<endl;
    }

    //Inserting grades
    grades.insert(grades.begin() , 100); // insert 100 at 0th index;
    grades.insert(grades.end()-1 , 75); // insert element before last element

    cout<<"Printing All grades after insertion operation : "<<endl;
    for (auto i : grades) {
        cout<<i <<" ";
    }
    cout<<endl;
    cout<<"Size of  Vector after insertion operation : "<<grades.size()<<endl;


    //removing grades
    grades.pop_back(); // remvoes last element
    grades.erase(grades.begin()+1);// erases 2nd element and, shrink the vector
    cout<<"Printing All grades after removal operation : "<<endl;
    for (auto i : grades) {
        cout<<i <<" ";
    }
    cout<<endl;
    cout<<"Size of Vector after removal operation : "<<grades.size()<<endl;


    //clearing vector
    grades.clear();
    cout<<"Size of Vector after clear operation : "<<grades.size()<<endl;
    cout<< (grades.empty() ? "Empty Vector" :"NonEmpty Vector")<<endl;

}
