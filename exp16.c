#include <stdio.h>
#include <stdlib.h>

#define SIZE 10   
int hashTable[SIZE];
void initTable() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;  // -1 indicates empty slot
    }
}
int hash(int key) {
    return key % SIZE;
}
void insert(int key) {
    int index = hash(key);
    int i = 0;

    while (hashTable[(index + i) % SIZE] != -1) {
        i++;
        if (i == SIZE) {
            printf("Hash Table Overflow! Cannot insert %d\n", key);
            return;
        }
    }
    hashTable[(index + i) % SIZE] = key;
    printf("%d inserted at index %d\n", key, (index + i) % SIZE);
}
void search(int key) {
    int index = hash(key);
    int i = 0;

    while (hashTable[(index + i) % SIZE] != -1) {
        if (hashTable[(index + i) % SIZE] == key) {
            printf("%d found at index %d\n", key, (index + i) % SIZE);
            return;
        }
        i++;
        if (i == SIZE) break;
    }
    printf("%d not found in the table.\n", key);
}
void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != -1)
            printf("Index %d -> %d\n", i, hashTable[i]);
        else
            printf("Index %d -> EMPTY\n", i);
    }
}
int main() {
    int choice, key;
    initTable();

    while (1) {
        printf("\n--- Hashing using Linear Probing ---\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(key);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
