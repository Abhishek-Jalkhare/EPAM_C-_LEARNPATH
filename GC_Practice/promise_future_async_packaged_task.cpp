//
// Created by AbhishekJalkhare on 11-05-2026.
//

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void dataIntialiser(promise<int> p ) {
    this_thread::sleep_for(chrono::seconds(2));
    p.set_value(12);
    return ;
}

long long calculate_factorial(int n) {
    if (n == 1) return 1;
    return 1ll*calculate_factorial(n-1)*n;
}
void processAsync( int val , std::function<void(int)> callback ) {
    std::chrono::seconds(2);
    callback(val*val);
}

int main(int argc, char *argv[]) {
    promise<int> p;
    future<int> f = p.get_future();
    dataIntialiser(move(p));
    int n = f.get();
    packaged_task<long long (int)> pt(calculate_factorial);
    int res = pt.get_future().get();

    processAsync(res , [](int x) {
        cout<<"res : "<<x<<endl;
    });
}
