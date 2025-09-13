#include <stdio.h>

// Recursive function to return the nth Fibonacci number
int fibonacci(int n) {
    if (n == 0)
        return 0; // Base case
    else if (n == 1)
        return 1; // Base case
    else
        return fibonacci(n - 1) + fibonacci(n - 2); // Recursive case
}

int main() {
    int terms, i;

    printf("Enter the number of terms: ");
    scanf("%d", &terms);

    if (terms <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    printf("Fibonacci Series up to %d terms:\n", terms);
    for (i = 0; i < terms; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");

    return 0;
}
