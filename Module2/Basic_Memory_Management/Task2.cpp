//
// Created by AbhishekJalkhare on 28-01-2026.
//

#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    int n = 5;
    int * arr1  = new int[n];
    for (int i = 0 ; i < n ; i++)
    {
        arr1[i] = 0;
    }
    cout<<"Array created using new"<<endl;
    for (int i = 0 ; i < n ; i++)
    {
        cout<<i<<" ELement :" <<arr1[i]<<endl;
    }

    delete[] arr1;

    int * arr2 = (int*)malloc(n*sizeof(int));
    for (int i = 0 ; i < n ; i++)
    {
        arr2[i] = 0;
    }
    cout<<"Array created using malloc"<<endl;
    for (int i = 0 ; i < n ; i++)
    {
        cout<<i<<" ELement :" <<arr2[i]<<endl;
    }

    free (arr2);

}
