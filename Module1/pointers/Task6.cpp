//
// Created by AbhishekJalkhare on 02-02-2026.
//

#include<stdio.h>
#include<stdlib.h>

int add( int a , int b ){
    return a+b;
}

int subtract (int a , int b){
    return a - b;
}

int multipy(int a , int b){
    return  a*b;
}


int main(int argc, char const *argv[])
{
    int a = 1, b = 2;
    int(*fp) (int ,int) = add;
    printf("%d",fp(1,2));

    fp = subtract;
    printf("%d",fp(1,2));

    fp = multipy;
    printf("%d",fp(1,2));

    return 0;
}
