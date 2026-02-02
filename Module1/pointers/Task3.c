//
// Created by AbhishekJalkhare on 02-02-2026.
//
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void inputScore(int* , int);
double calculateAverage(const int* , int );
int findHighest(const int* , int );

int main(int argc, char* argv[]) {
    int n;
    printf("Enter the total number of innings played (must be positive): ");
    scanf("%d \n" , &n);
    while (n <= 0) {
        printf("Number of games must be positive. Please re-enter.\n");
        scanf("%d \n" , &n);
    }

    int * innigsScores = malloc(n * sizeof(int));
    if (innigsScores == NULL) {
        printf("Bad ALoocation \n");
        return 1;
    }
    inputScore(innigsScores , n);
    printf("Average of scores %lf \n" , calculateAverage(innigsScores , n));
    printf("Highest Score : %d" , findHighest(innigsScores,n));
    free(innigsScores);
    innigsScores = NULL;
}

void inputScore( int* scoresPtr , int size) {
    for (int i = 0 ; i < size ; i++) {
        printf("Enter score for Game #[%d] (0-100): " , i+1);
        int score;
        do {
            scanf("%d" , &score);
        }while (score < 0 || score > 100);
        scoresPtr[i] = score;
    }
}

double calculateAverage(const int* scoresPtr, int size) {
    if (scoresPtr == NULL) {
        printf("Invalid array");
        return -1;
    }
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += scoresPtr[i];
    }
    double avg = (double)(sum)/size;
    return avg;
}

int findHighest(const int* scoresPtr, int size) {
    if (scoresPtr == NULL) {
        printf("Invalid array");
        return -1;
    }
    int max = INT_MIN;
    for (int i = 0 ; i < size ; i++) {
        if (scoresPtr[i] > max) max = scoresPtr[i];
    }
    return max;
}




