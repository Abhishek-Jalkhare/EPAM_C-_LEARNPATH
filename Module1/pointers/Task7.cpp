//
// Created by AbhishekJalkhare on 02-02-2026.
//

#include <stdio.h>
#include <stdlib.h>


int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b == 0) {
        printf("Error: Division by zero is not allowed.\n");
        exit(EXIT_FAILURE);   // Proper error handling
    }
    return a / b;
}


int calculate(int a, int b, int (*operation)(int, int)) {
    return operation(a, b);
}

int main(void) {

    int result;


    result = calculate(20, 5, add);
    printf("20 + 5 = %d\n", result);

    result = calculate(20, 5, subtract);
    printf("20 - 5 = %d\n", result);

    result = calculate(20, 5, multiply);
    printf("20 * 5 = %d\n", result);

    result = calculate(20, 5, divide);
    printf("20 / 5 = %d\n", result);

    printf("\nTesting division by zero:\n");
    result = calculate(10, 0, divide);  // Will trigger error

    return 0;
}
