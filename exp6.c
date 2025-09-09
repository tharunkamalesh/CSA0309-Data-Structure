#include <stdio.h>

// Recursive function to find nth Fibonacci number
int fibonacci(int n) {
    if (n == 0)
        return 0;  
    else if (n == 1)
        return 1;  
    else
        return fibonacci(n - 1) + fibonacci(n - 2); 
}

int main() {
    int n, i;
    printf("Enter the number of terms in Fibonacci series: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer.\n");
    } else {
        printf("Fibonacci Series up to %d terms:\n", n);
        for (i = 0; i < n; i++) {
            printf("%d ", fibonacci(i));
        }
        printf("\n");
    }

    return 0;
}
