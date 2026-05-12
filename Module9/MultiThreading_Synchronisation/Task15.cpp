//
// Created by AbhishekJalkhare on 13-04-2026.
//

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void fun(promise<int>prom) {
    // simulating calculationa
    this_thread::sleep_for(chrono::seconds(2));
    prom.set_value(40);
}

int main(int argc, char *argv[]) {
    promise<int> p ;
    future<int> f = p.get_future();
    thread t(fun , std::move(p));
    cout<<f.get();
    t.join();
}
