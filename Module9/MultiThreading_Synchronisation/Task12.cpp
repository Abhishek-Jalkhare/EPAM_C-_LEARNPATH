//
// Created by AbhishekJalkhare on 09-04-2026.
//

// Takes an array of integers and divides it into N nearly equal chunks Spawns N threads;
// each thread calculates the sum of its allocated chunk Stores each thread’s result in a separate value
// The main thread waits (joins) for all threads and then adds the partial sums for the final total

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

mutex mtx;
vector<int> vec(100000 , 0);

long long sum(int s , int e ) {
    long long sum = 0;
    for (int i = s ; i <= e ; i++) {
        sum += vec[i];
    }
    return sum;
}

void execute(const int s, const int e, vector<long long> &res, long long(*fun)(int, int))  {
    long long sum = fun(s,e);
    lock_guard<mutex>lg(mtx);
    res.push_back(sum);
}

int main(int argc, char *argv[]) {
    iota(vec.begin()  ,vec.end() , 0);
    vector<long long>res; // make the push_back operation thread safe
    vector<thread> threads;
    int n = 10000;
    for (int i = 0 ; i < vec.size() ; i+=n) {
        threads.emplace_back(execute ,i , i+n-1 ,ref(res) ,sum);
    }

    for (auto& a : threads) {
        a.join();
    }

    const long long sum = accumulate(res.begin() , res.end() , 0ll);
    cout<<"Sum : "<<sum<<endl;
}
