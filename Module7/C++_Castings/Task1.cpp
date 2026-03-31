//
// Created by AbhishekJalkhare on 16-03-2026.
//
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    int a = 12;
    double d = 1.7;

    cout<<"Static Cast (int to double) : "<<static_cast<double>(a)<<endl;
    cout<<"C-Style Cast (int to double) : "<<(double)a<<endl;
    cout<<"Static Cast (double to int ) : "<<static_cast<int>(d)<<" (Truncate)"<<endl;
    cout<<"C-Style Cast (double to int ) : "<<(int)d<<" (Truncate)"<<endl;

    /*
    static_cast is preferred over C-style casts because:
      - It's more explicit and searchable in code.
      - It disallows dangerous reinterpretation or narrowing conversions unless explicit.
      - C-style cast can perform several kinds of conversions (static, const, reinterpret) and is therefore riskier.
      - static_cast is easier to find in code review and refactoring.
    */
}
