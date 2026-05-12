//
// Created by AbhishekJalkhare on 20-04-2026.
//

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int dat = 0;
shared_mutex mtx;

void reader() {
    shared_lock<shared_mutex> sl(mtx);
    osyncstream(cout)<<"Reading Value : "<<dat<<endl;

}

void writer(int val) {
    unique_lock<shared_mutex> ul(mtx);
    dat = val;
    cout<<"Setting the Value( "<<val<<" ) ....."<<endl;
}


int main(int argc, char *argv[]) {
    vector<thread> vec;
    vec.emplace_back(reader);
    vec.emplace_back(reader);
    vec.emplace_back(writer,23);
    vec.emplace_back(reader);
    vec.emplace_back(writer,45);
    vec.emplace_back(writer,67);
    vec.emplace_back(writer,71);
    vec.emplace_back(reader);
    vec.emplace_back(reader);
    vec.emplace_back(writer,99);
    vec.emplace_back(reader);

    for (auto& t : vec) t.join();
}
