#include <stdio.h>

// Binary Search function (iterative)
int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1, mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == target)
            return mid;  // Element found
        else if (arr[mid] < target)
            low = mid + 1;  // Search right half
        else
            high = mid - 1; // Search left half
    }

    return -1;  // Element not found
}

int main() {
    int arr[100], n, target, result;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements in **sorted order**:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number to search: ");
    scanf("%d", &target);

    result = binarySearch(arr, n, target);

    if (result == -1)
        printf("Element %d not found in the array.\n", target);
    else
        printf("Element %d found at position %d (index %d).\n", target, result + 1, result);

    return 0;
}
