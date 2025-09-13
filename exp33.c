#include <stdio.h>

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            return i; // Return index if found
    }
    return -1; // Return -1 if not found
}

int main() {
    int arr[100], n, target, result;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number to search: ");
    scanf("%d", &target);

    result = linearSearch(arr, n, target);

    if (result == -1)
        printf("Element %d not found in the array.\n", target);
    else
        printf("Element %d found at position %d (index %d).\n", target, result + 1, result);

    return 0;
}
