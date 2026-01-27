//
// Created by Abhishek Jalkhare on 26-01-2026.
//
#include<iostream>
#include<queue>
using namespace  std;

int main(int argc, char *argv[]) {
    queue<int> qu ;
    qu.back();
    qu.front();
    qu.push(1);
    qu.push(6);
    qu.push(5);
    qu.push(4);
    qu.push(3);
    qu.push(2);
    qu.pop(); // removes element from the begining of the quue

    cout<<qu.front()<<endl;
}
