//
// Created by AbhishekJalkhare on 03-02-2026.
//
#include <iostream>
using namespace std;

class Calculator {
public:
    [[nodiscard]] static int add ( int a , int b )  {
        return a + b;
    }

    [[nodiscard]] static double add(double a , double b) {
        return a + b;
    }

    // [[nodiscard]]static const string& add(const string& a, const string& b ) {
    //     // string s = a + b; retruning refrene of s will be incorrect because s will be destroyed after
    //     //function call
    //     return a + b; // this will be also destroyed after function call
    // }

    [[nodiscard]]static string add(const string& a , const string& b) {
        return a + b;
    }
};

int main(int argc, char* argv[]) {
    cout<<"Calling add method with 2 int's 1 , 2 : "<<Calculator::add(1,2)<<endl;
    cout<<"Calling add method with 2 double's 1.3 , 2.5 : "<<Calculator::add(1.3,2.5)<<endl;
    cout<<"Calling add method with 2 strings : Hello , ! : "<<Calculator::add("Hello" , " !")<<endl;

}
