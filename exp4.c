#include <stdio.h>

int main() {
    int n, i;
    long long first = 0, second = 1, next;
    printf("Enter the number of terms in Fibonacci series: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer.\n");
    } else {
        printf("Fibonacci Series up to %d terms:\n", n);

        for (i = 1; i <= n; i++) {
            if (i == 1) {
                printf("%lld ", first);
                continue;
            }
            if (i == 2) {
                printf("%lld ", second);
                continue;
            }

            next = first + second;
            first = second;
            second = next;

            printf("%lld ", next);
        }
        printf("\n");
    }

    return 0;
}
