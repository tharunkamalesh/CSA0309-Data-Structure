#include <stdio.h>

int main() {
    int a[100], b[100], merged[200];
    int n1, n2, i, k = 0;

    // Input first array
    printf("Enter number of elements in first array: ");
    scanf("%d", &n1);
    printf("Enter elements of first array:\n");
    for (i = 0; i < n1; i++) {
        scanf("%d", &a[i]);
        merged[k++] = a[i];
    }

    // Input second array
    printf("Enter number of elements in second array: ");
    scanf("%d", &n2);
    printf("Enter elements of second array:\n");
    for (i = 0; i < n2; i++) {
        scanf("%d", &b[i]);
        merged[k++] = b[i];
    }

    // Print merged array
    printf("Merged Array:\n");
    for (i = 0; i < n1 + n2; i++) {
        printf("%d ", merged[i]);
    }

    return 0;
}
