//
// Created by AbhishekJalkhare on 02-02-2026.
//

#include <stdio.h>

int main() {
    char name1[20], name2[20], name3[20];
    int age1, age2, age3;
    float gpa1, gpa2, gpa3;

    printf("Enter details for Student 1\n");
    printf("Name: ");
    scanf("%19s", name1);
    printf("Age: ");
    scanf("%d", &age1);
    printf("GPA: ");
    scanf("%f", &gpa1);

    printf("\nEnter details for Student 2\n");
    printf("Name: ");
    scanf("%19s", name2);
    printf("Age: ");
    scanf("%d", &age2);
    printf("GPA: ");
    scanf("%f", &gpa2);

    printf("\nEnter details for Student 3\n");
    printf("Name: ");
    scanf("%19s", name3);
    printf("Age: ");
    scanf("%d", &age3);
    printf("GPA: ");
    scanf("%f", &gpa3);

    printf("\n%-15s %5s %6s\n", "Name", "Age", "GPA");
    printf("--------------------------------\n");

    printf("%-15s %5d %6.2f\n", name1, age1, gpa1);
    printf("%-15s %5d %6.2f\n", name2, age2, gpa2);
    printf("%-15s %5d %6.2f\n", name3, age3, gpa3);

    return 0;
}
