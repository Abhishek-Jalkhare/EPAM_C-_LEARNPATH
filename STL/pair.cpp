//
// Created by AbhishekJalkhare on 26-01-2026.
//

#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int main(int argc, char *argv[]) {
    pair<int , int> pr = {1,2} ;
    int a = pr.first;
    int b = pr.second;
    pair<int , pair<int ,int>> p = {1 , {1,2}};
    pair<int , int> arr[] = {{1,2} , {3,4}};
    cout<<arr[0].first<<endl;
    cout<<arr[0].second<<endl;
}
