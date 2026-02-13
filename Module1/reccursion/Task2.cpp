#include<iostream>
using namespace std;

int cache[1001];
int countWays(int n);


int main(int argc, char const *argv[])
{
    cout<<"Enter the number of stairs: between 0 to 1000 "<<endl;
    int n;
    cin>>n;
    if(n<0 || n>1000){
        cout<<"Invalid Input enter number between 0 and 1000"<<endl;
        return 0;
    }
    for(int i=0;i<=n;i++){
        cache[i]=-1;
    }

    cout<<"Number of ways to climb the stairs: "<<countWays(n)<<endl;
    return 0;
}

int countWays(int n) {
    if (n < 0) return 0;
    if (n == 0) return 1;

    if (cache[n] != -1) return cache[n];

    cache[n] = countWays(n - 1) + countWays(n - 2);
    return cache[n];
}