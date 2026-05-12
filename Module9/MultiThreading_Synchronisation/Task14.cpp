//
// Created by AbhishekJalkhare on 13-04-2026.
//
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int longComputation() {
    this_thread::sleep_for(chrono::seconds(2));
    // some complex calculations
    return 40;
}

int main(int argc, char *argv[]) {
    future<int>f1 = async(launch::async , longComputation);

    cout<< f1.get()<<endl; // main thread waits here
    cout<<"Program completed"<<endl;
}
