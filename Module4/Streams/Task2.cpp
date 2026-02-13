//
// Created by AbhishekJalkhare on 09-02-2026.
//
#include <iomanip>
#include<iostream>
#include <vector>
using namespace std;

struct Item {
    string name;
    float price;
};

int main(int argc, char* argv[]) {
    vector<Item*> vec {new Item{"Apple",1.504343} ,
    new Item{"Banana",0.99}};
    cout<<fixed<<setprecision(2);
    cout<<setw(10)<<left<<"Item"<<setw(10)<<"Price"<<endl;
    for (const auto i : vec) {
        cout<<setw(10)<<left<<i->name<<setw(10)<<i->price<<endl;
    }
}
