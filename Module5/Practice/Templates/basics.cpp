//
// Created by AbhishekJalkhare on 19-02-2026.
//

#include <iostream>
using namespace  std;

template<typename   T>
class calculator {
public:
    T add(T a , T b) {
        return a + b;
    }

    T sub(T a , T b) {
        return a - b;
    }
};


//creating a class to allocate array on stack
template<typename T , int N>
// this code is not compiled till we call it ;
class MyStackArray {
public:
    T arr[N];
    int getSize() {
        return N;
    }
    template<>
    int getSize<float>{
    return 1 + N;
    }
};
template<typename T>
T add(T a , T b) {
    return a + b;
}

// template specilaisation - if you want a special implementation for a type
template<>
int add<int> (int a , int b) {
    return a + b + 100;
}




int main(int argc, char* argv[]) {
    MyStackArray<int , 100>arr;
    calculator<int> c;
    c<float>.add(1,2);
    cout<<add(1,2)<<endl; // implicit type detection
    cout<<add<int>(1,2.4)<<endl; // explicit type

}

