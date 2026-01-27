//
// Created by AbhishekJalkhare on 26-01-2026.
//
#include <iostream>
#include <list>
#include <vector>
using namespace std;


int main(int argc, char *argv[]) {
    vector<int> v1;
    vector<int> v2(6 , -1); // 5 element with -1 as intial value
    vector<int> v3 (v2);
    vector<pair<int , int>> v4;
    vector<int> v5(5); // size 5;
    //  vector<int> v6 (-1 , 5); // invalid

    // using iterator
    for (vector<int> :: iterator it = v2.begin() ; it != v2.end() ; ++it)
        cout<<*it<<endl;

    //instead you can use
    for (auto it = v2.begin() ; it != v2.end() ; ++it){}

    // methods
    v1.push_back(1);
    v2.emplace_back(2); // it is faster than push back
    v1.back() ;// gets last element
    v2.erase(v2.begin() + 2); // adress of single element to delete
    // v2.erase(start index , end+1)
    v1.insert(v2.begin() , 12); // insert value at position
    // v2.insert( start add , number of element to insert , element )
    // v2.insert(beguning add , another vector begin index , another vector end)
    // this will insert element from begging of another vect till end index of another vector

    v1.size();
    v1.pop_back();   // deletes last elemnt
    v1.clear(); // erses vector
    v1.empty();

    // list same as vector but we can also insert element form front
    pmr::list<int> ls = {1,2,4};

    ls.push_back(1);
    ls.push_front(1);
}
