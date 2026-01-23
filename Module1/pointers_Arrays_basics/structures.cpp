#include <iostream>
using namespace std;

struct SampleStruct {
    char a;
    char c;
    int b;
};

int main(int argc, char const *argv[])
{
    /* codes */
    SampleStruct sample{'a', 42, 'b'};
    cout<<"size of members: "<<sizeof(sample.a) + sizeof(sample.b) + sizeof(sample.c) << " bytes" << endl;
    cout << "Size of SampleStruct: " << sizeof(SampleStruct) << " bytes" << endl;
    return 0;
}
