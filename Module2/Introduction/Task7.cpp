//
// Created by AbhishekJalkhare on 27-01-2026.
//

#include <iostream>
using namespace std;

#define  SQUARE(x)  x * x
inline int square (int x ) {return x * x;}


int main(int argc, char *argv[]) {
    cout<<SQUARE(2)<<endl;
    cout<<square(2)<<endl;

    cout<<"Calling using parameter : 2 + 3 "<<endl;
    cout<<"Using Macro"<<SQUARE(3+2)<<endl;
    cout<<"using inline fucntion :" << square(3 + 2)<<endl;
}
