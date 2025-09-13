#include <stdio.h>
#define MAX 100

// Function to insert an element
void insert(int arr[], int *n, int pos, int val) {
    if (*n >= MAX) {
        printf("Array is full! Cannot insert.\n");
        return;
    }
    if (pos < 0 || pos > *n) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1]; // Shift elements to the right
    }

    arr[pos] = val;
    (*n)++;
    printf("Element inserted successfully.\n");
}

// Function to delete an element
void delete(int arr[], int *n, int pos) {
    if (*n <= 0) {
        printf("Array is empty! Cannot delete.\n");
        return;
    }
    if (pos < 0 || pos >= *n) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1]; // Shift elements to the left
    }

    (*n)--;
    printf("Element deleted successfully.\n");
}

// Function to display the array
void display(int arr[], int n) {
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }

    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX], n = 0;
    int choice, val, pos;

    while (1) {
        printf("\n----- Array Operations Menu -----\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter position to insert (0 to %d): ", n);
                scanf("%d", &pos);
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insert(arr, &n, pos, val);
                break;
            case 2:
                printf("Enter position to delete (0 to %d): ", n - 1);
                scanf("%d", &pos);
                delete(arr, &n, pos);
                break;
            case 3:
                display(arr, n);
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
