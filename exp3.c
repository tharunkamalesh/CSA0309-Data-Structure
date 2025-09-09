#include <stdio.h>

int main() {
    int n, i;
    unsigned long long factorial = 1; 
    printf("Enter a number to find its factorial: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("Factorial of a negative number is not defined.\n");
    } else {
        for (i = 1; i <= n; i++) {
            factorial *= i;
        }
        printf("Factorial of %d = %llu\n", n, factorial);
    }

    return 0;
}
