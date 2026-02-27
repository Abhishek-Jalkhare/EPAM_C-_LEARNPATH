//
// Created by AbhishekJalkhare on 20-02-2026.
//

#include <iostream>
#include <vector>
using namespace std;
template < typename  ...Args >
class MyTuple {
    tuple<Args...>tpl;
public:
    explicit MyTuple(Args ...args):tpl(args...) {}
    template<unsigned int index = 0>
    void printAll() {
        if constexpr (index < sizeof...(Args)) {
            cout<<(get<index>(tpl))<<" ";
            printAll<index+1>();
        }
        else cout<<endl;
    }

};

int main(int argc, char* argv[]) {
    MyTuple<int , int, int> tpl{1,2,3};
    tpl.printAll();
    tpl.printAll();
    vector<int>v{1,2,4};
}
