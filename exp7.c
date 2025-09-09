#include <stdio.h>

#define MAX 100

void display(int arr[], int n) {
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements are: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insert(int arr[], int *n, int pos, int value) {
    if (*n >= MAX) {
        printf("Array is full! Cannot insert.\n");
        return;
    }
    if (pos < 0 || pos > *n) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    (*n)++;
    printf("Inserted %d at position %d.\n", value, pos);
}

void delete(int arr[], int *n, int pos) {
    if (*n == 0) {
        printf("Array is empty! Cannot delete.\n");
        return;
    }
    if (pos < 0 || pos >= *n) {
        printf("Invalid position!\n");
        return;
    }
    int deleted = arr[pos];
    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
    printf("Deleted %d from position %d.\n", deleted, pos);
}

int main() {
    int arr[MAX], n = 0, choice, pos, value;

    do {
        printf("\n--- Array Operations Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter position (0-based index): ");
                scanf("%d", &pos);
                printf("Enter value: ");
                scanf("%d", &value);
                insert(arr, &n, pos, value);
                break;

            case 2:
                printf("Enter position (0-based index): ");
                scanf("%d", &pos);
                delete(arr, &n, pos);
                break;

            case 3:
                display(arr, n);
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
