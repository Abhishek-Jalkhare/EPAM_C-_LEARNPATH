//
// Created by AbhishekJalkhare on 20-02-2026.
//
#include <iostream>
using namespace std;

    template<typename T , typename ...Args >
    T sum( T t,Args ... arg) {
        return (t + ...+ arg); // here the return type will be the first element type
    }

    template<typename  ...Args>
    auto sum(Args...arg) {
        // return(arg+...); // best use auto , but fails for sum()
        return (arg+ ... + 0); // evaluation order for(1,2,3,4,5) -> (((1 +2)+3)+4)+5 left fold
        // for ...+arg+ 0 // evaluation order               1+(2+(3+(4+5))) + 0;
    }
     int sum1() { // base case should always declared first beacuse compiler would not know that it exist and we get
        // error for sum() call;
        return 0;
    }

   template<typename First , typename ...Args>
    First sum1( First f , Args...args ) {
        return f + sum1(args...);
    }


int main(int argc, char* argv[]) {
        cout<<sum1(1,2,3,4)<<endl;
    // cout<<sum(1.0,2,3,4,5,6,7,8.6,9)<<endl;
        int x = 10;
        int && y = 10;
        y = x;

}


