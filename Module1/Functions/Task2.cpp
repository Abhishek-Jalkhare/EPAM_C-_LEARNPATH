//
// Created by AbhishekJalkhare on 02-02-2026.
//
#include <iostream>
using namespace std;

float calculateAverage(int* marks, int numSubjects);
char determineGrade(float average);
void displayResults(float average, char grade , int numSubjects , int* marks);

int main(int argc, char const *argv[])
{
    int n ;
    cout<<"Enter number of subjects: ";
    cin>>n;
    int * marks = new int[n];
    for (int i = 0; i < n; i++){
        cout<<"Enter marks for subject "<< i + 1 <<": ";
        cin>>marks[i];
    }
    int average = calculateAverage(marks, n);
    char grade = determineGrade(average);
    displayResults(average, grade , n , marks);
    delete[] marks;

    return 0;
}

float calculateAverage(int marks[], int numSubjects){

    int total = 0;
    for (int i = 0; i < numSubjects; i++) {
        total += marks[i];
    }
    return (float)(total) / numSubjects;
}

char determineGrade(float average) {
    if (average >= 90) {
        return 'A';
    } else if (average >= 80) {
        return 'B';
    } else if (average >= 70) {
        return 'C';
    } else if (average >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}

void displayResults(float average, char grade , int numSubjects , int marks[]){
    cout<<"Number of Subjects: "<< numSubjects << endl;
    cout<<"Marks: ";
    for (int i = 0; i < numSubjects; i++) {
        cout<< marks[i] << " ";
    }
    cout<<endl;
    cout<<"Average Marks: "<< average << endl;
    cout<<"Grade: "<< grade << endl;
}