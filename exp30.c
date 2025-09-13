#include <stdio.h>

// Function to calculate factorial using recursion
long long factorial(int n) {
    if (n == 0 || n == 1)
        return 1;  // Base case
    else
        return n * factorial(n - 1);  // Recursive case
}

int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    if (num < 0)
        printf("Factorial is not defined for negative numbers.\n");
    else {
        long long result = factorial(num);
        printf("Factorial of %d is: %lld\n", num, result);
    }

    return 0;
}
