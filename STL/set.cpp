//
// Created by AbhishekJalkhare on 27-01-2026.
//
#include <set>
#include <iostream>
#include <unordered_set>

using namespace std;

int main(int argc, char *argv[]) {
    set<int> st ; // sorted + unique
    unordered_set<int> st1 ; //
    multiset<int> st2; // sorted only can contain duplicate but if we delete an element all its ,
    // occurrences are deleted
    st1.insert(11);
    st1.insert(2);
    st1.insert(13);
    st1.insert(41);
    st1.insert(5);

    for (int x : st1) {
            cout<<x<<endl;
    }
    st.find(4);
    st1.find(4);
    // if element not in set it return set.end()

    st.count(1);
    // st.erase(begin , end)
    // count occurences of n if not present then 0

    st.insert(11);
    st.insert(2);
    st.insert(13);
    st.insert(41);
    st.insert(5);
    // for (int x : st) {
    //     cout<<x<<endl;
    // }
    multiset<int  > mlt ;
    mlt.insert(1);
    mlt.insert(6);
    mlt.insert(3);
    mlt.insert(1);

    cout<<*mlt.rbegin() ;




}
