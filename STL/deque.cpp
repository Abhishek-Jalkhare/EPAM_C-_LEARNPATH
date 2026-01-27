//
// Created by AbhishekJalkhare on 26-01-2026.
//

#include <deque>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    deque<int>dq;

    dq.push_back(1);
    dq.emplace_back(1);


    dq.push_front(2);
    dq.emplace_front(2);

    dq.back();
    dq.front();

}
