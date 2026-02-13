//
// Created by AbhishekJalkhare on 06-02-2026.
//
#include <stdio.h>
#include <stdlib.h>
//we can not do assingment as increment aperator to array tyoe eg arr[3];
// arr type is of const pointer to 1st ele
//but we can store it in another pointer then increment or modify that pointer
//so static array bechaves like int * const arr
//but if we use dynamic memory allocation for array it returns a normal pointer
int main(int argc, char* argv[]) {
    int arr []  = {1,2,3};

   char*  arr1 [] = {"add" , "sub" , "mul","gfh"};
    char ** temp = arr1+1;
   char*  arr2 [] = {"add" , "sub" , "mul" , "div"};
   char** arr3 = (char*[]){"add" , "sub"};  // here compiler creates a char*[] and intialise it to values in braces
   arr3++;

    // printf("%d",*(arr++));error
    printf("%s",*(--temp));

   // char c='a';
   //  char* ptr1="abc";
   //  char** ptr_to_ptr;
   //  ptr_to_ptr[0] = ptr1;
   //  printf("%s\n",*ptr_to_ptr[0]);
    // printf("%p\n",ptr1);
    // printf("%c\n",*ptr1);
    // printf("%c\n",**ptr_to_ptr);

    // arr1=arr2;
    // printf("addresss of 1st ele arr1 %p \n " , arr1);
    // printf("addresss of 1st ele arr2 %p \n " , arr2);
    // printf("First elm of arr1 %s\n",*arr1);
    // printf("First elm of arr2 %s\n",*arr2);

    if (arr1==arr2)
        printf("Ho gaya!");



}

