//
// Created by AbhishekJalkhare on 25-03-2026.
//
#include <iostream>
#include <list>
#include <algorithm>
#include <limits>
using namespace std;

void printList(list<int>li) {
    ranges::for_each(li,[](int x) {
        cout<<x<<" ";
    });
    cout<<endl;
}

int main(int argc, char* argv[]) {

    list<int> li = {1,2,3,2,3,5,4,2,7,2,3};
    const size_t size = li.size();
    if (size == 0) {
        cout<<"List is EMpty"<<endl;
        return 1;
    }
    cout<<"Enter a Value to remove from a list"<<endl;
    int val;
    while (true){
        cin>>val;
        if (cin.fail()) {
            cout<<"Enter valid value";
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max()) , '\n');
        }
        else break;
    }

    li.remove(val);
    if (li.size() == size) {
        cout<<"Element Not Found"<<endl;
    }
    else {
        cout<<"Element removed successfully"<<endl;
    }
    printList(li);

    // manual implementation
    li = {1,2,3,2,3,5,4,2,7,2,3};
    cout<<"Manual Implementation "<<endl;
    for (auto it = li.begin() ; it != li.end() ; ) {
        if (*it == val) {
            it = li.erase(it);
        }
        else ++it;
    }
    if (li.size() == size) {
        cout<<"NO element removed"<<endl;
    }
    else {
        cout<<"element removed successfully"<<endl;
    }
    printList(li);
}
