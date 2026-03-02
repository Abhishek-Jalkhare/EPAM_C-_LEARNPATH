//
// Created by AbhishekJalkhare on 02-03-2026.
//

#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    int arr [] = {1,2,4};
    auto a = arr; // type of a -> int
    auto& b = arr; // type of b -> int(&)[3]
    auto && c = arr;
    const auto d  = arr;  //int* const(const pointer)
    auto && e = move(arr);
    // int &f[3] = arr wrong because it is deduced as  f is array of 3 refrence and refrences
    // can't be in arry because they can't be intialised or reseated

    int (&f)[3] = arr; // f is a refrence to array of 3 ints
}
