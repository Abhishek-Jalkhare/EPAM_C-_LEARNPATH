#include<iostream>
using namespace std;



void fun(int a) {
     cout<<"int"<<endl;
 }

void fun(double a) {
     cout<<"double"<<endl;
 }
void fun(float a) {
     cout<<"float"<<endl;
 }
void fun(unsigned int a) {
     cout<<" unint"<<endl;
 }
void fun(short a) {
     cout<<"short"<<endl;
 }
void fun(bool a) {
     cout<<"bul"<<endl;
 }

void fun(char * a) {
    cout<<"string"<<endl;
}

void fun(long long a) {
    cout<<"lopng long"<<endl;
}

int main ()
{
    fun(1);

}