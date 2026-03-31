//
// Created by AbhishekJalkhare on 25-03-2026.
//
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
constexpr size_t CACHE_CAPACITY = 6;
void accessCache(list<int>& cache,const int value) {
    auto it = ranges::find(cache ,value);
    // If element exists, remove it from current position
    if (it != cache.end()) {
        cache.erase(it);
    }
    // If cache is full and element wasn't present, remove LRU
    else if (cache.size() == CACHE_CAPACITY) {
        cache.pop_back();
    }

    // Add element to front (most recently used)
    cache.push_front(value);
}
void printCache(list<int>& cache) {
    cout<<"Printing cache ...."<<endl;
    ranges::for_each(cache , [](const int x) {
        cout<<x << " ";
    });
    cout<<endl;
}

int main() {
    list<int>cache;
    while (true) {
        int value;
        cout << "Access value: ";
        cin >> value;
        if (value == -1) break; // Stop input accessCache(cache, value); printCache(cache); }
        accessCache(cache ,value);
        printCache(cache);
    }
}