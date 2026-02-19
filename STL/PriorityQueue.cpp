//
// Created by AbhishekJalkhare on 27-01-2026.
//
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
    vector<int> vec{2,4,2,7,6,4};
    int x=4;
    int y =6;



    auto comp=[&](int y,int b) {
        y+=6;
        cout<<"inside lambda"<<y<<endl;
        return b+x;

    };

    int sum=comp(y,4);
    // sort(vec.begin(),vec.end(),[](int a,int b) {
    //     return a>b;
    // });
    // for (auto x:vec)
    //     cout<<x<<" ";
    cout<<"outside lambda"<<y<<endl;
    cout<<sum;


    priority_queue<int, vector<int> , greater<int>> pq; // default max heap

    pq.push(21);
    pq.push(291);
    pq.push(211);
    pq.push(2);

    pq.push(212);

    while (!pq.empty()) {
        int a = pq.top();
        pq.pop();
        cout<<endl<<"Ele :"<<a<<endl;
    }

}

struct A {
    operator()() {

    }
};