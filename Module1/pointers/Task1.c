//
// Created by AbhishekJalkhare on 02-02-2026.
//
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int* theme_color_code = malloc(sizeof(int));
    if (theme_color_code == NULL) {
        printf("Memory Allocation failed \n");
        return 0;
    }
    *theme_color_code = 0;

    printf("Enter your prefferd color code integer value \n");
    scanf("%d" , theme_color_code);

    printf("Final Color Code : %d \n" , *theme_color_code);
    free(theme_color_code);
    theme_color_code = NULL;
}
