//
// Created by AbhishekJalkhare on 12-03-2026.
//
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class ModernResource {
public:
    vector<int>vec;
    string s;
    shared_ptr<int>ptr;

    ModernResource(string s , const initializer_list<int>d  ) : vec(d),
    s(std::move(s)),
    ptr(make_shared<int>(1)){}

    void print(const char* tag) const {
        std::cout << tag << " " << s << ":";
        for (const int x : vec) std::cout << " " << x;
        std::cout << " | ptr=" << *ptr << std::endl;
    }
};

int main(int argc, char* argv[]) {
    ModernResource m1("first", {1,2,3});
    ModernResource m2 = m1;           // copy
    ModernResource m3("third", {3,4});
    m3 = std::move(m1);               // move
    m2.print("m2:");
    m3.print("m3:");
    // No leaks, safe operations, no custom copy/move/dtor code needed!
    return 0;
}
