//
// Created by AbhishekJalkhare on 02-02-2026.
//#include <iostream>
using namespace std;
double intrest ( double , double , double);

int main(){
    cout<<"Enter the Principal"<<endl;
    double p ;
    cin >> p;
    cout<<"Enter the rate"<<endl;
    double r ;
    cin >> r;
    cout<<"Enter the time"<<endl;
    double t ;
    cin >> t;
    cout<< "Intrest for the given data is " << intrest(p,r,t)<<endl;

}

double intrest (double p , double r , double t){
    return  p * r *t/100;
}

