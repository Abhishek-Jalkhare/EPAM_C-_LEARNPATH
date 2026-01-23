#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool validateRoll(int roll);
bool validateMarks(float marks);
void addStudentRecord(void);
void displayAllRecords(void);

struct Student {
    int roll_no;
    char name[50];
    float marks;
};

int main() {
    int choice;

    while (1) {
        printf("\n1 Add Student\n");
        printf("2 Display Records\n");
        printf("3 Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudentRecord();
                break;
            case 2:
                displayAllRecords();
                break;
            case 3:
                printf("Thank you for using Student Record Manager\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}

void addStudentRecord() {
    struct Student s;

    do {
        printf("Enter roll number: ");
        scanf("%d", &s.roll_no);
    } while (!validateRoll(s.roll_no));

    printf("Enter name: ");
    scanf(" %49[^\n]", s.name);

    do {
        printf("Enter marks (0-100): ");
        scanf("%f", &s.marks);
    } while (!validateMarks(s.marks));

    FILE *file = fopen("students.dat", "ab");
    if (file == NULL) {
        printf("File can't be opened\n");
        return;
    }

    fwrite(&s, sizeof(struct Student), 1, file);
    fclose(file);

    printf("Student record added successfully\n");
}

void displayAllRecords() {
    FILE *file = fopen("students.dat", "rb");
    if (file == NULL) {
        printf("No records found\n");
        return;
    }

    fseek(file, 0, SEEK_END);
    if (ftell(file) == 0) {
        printf("File is empty\n");
        fclose(file);
        return;
    }
    rewind(file);

    struct Student s;
    printf("\n----- ALL STUDENT RECORDS -----\n");

    while (fread(&s, sizeof(struct Student), 1, file) == 1) {
        printf("Roll Number : %d\n", s.roll_no);
        printf("Name        : %s\n", s.name);
        printf("Marks       : %.2f\n", s.marks);
        printf("--------------------------------\n");
    }

    fclose(file);
}

bool validateRoll(int roll) {
    return roll > 0;
}

bool validateMarks(float marks) {
    return marks >= 0.0f && marks <= 100.0f;
}
