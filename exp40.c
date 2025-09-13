 #include <stdio.h>
#define TABLE_SIZE 10

int hashTable[TABLE_SIZE];

// Initialize hash table with -1 indicating empty slot
void initialize() {
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = -1;
}

// Hash function (simple modulo)
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Insert key into hash table using linear probing
void insert(int key) {
    int index = hashFunction(key);
    int startIndex = index;

    while (hashTable[index] != -1) {
        index = (index + 1) % TABLE_SIZE;
        if (index == startIndex) {
            printf("Hash table is full, cannot insert %d\n", key);
            return;
        }
    }

    hashTable[index] = key;
    printf("Inserted %d at index %d\n", key, index);
}

// Search for a key in hash table
int search(int key) {
    int index = hashFunction(key);
    int startIndex = index;

    while (hashTable[index] != -1) {
        if (hashTable[index] == key)
            return index;
        index = (index + 1) % TABLE_SIZE;
        if (index == startIndex)
            break;  // Came full circle
    }
    return -1;  // Not found
}

// Display hash table
void display() {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != -1)
            printf("Index %d: %d\n", i, hashTable[i]);
        else
            printf("Index %d: Empty\n", i);
    }
}

int main() {
    initialize();

    int choice, key, pos;

    while (1) {
        printf("\n--- Hash Table Operations ---\n");
        printf("1. Insert\n2. Search\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
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
                pos = search(key);
                if (pos == -1)
                    printf("Key %d not found in the hash table.\n", key);
                else
                    printf("Key %d found at index %d.\n", key, pos);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice, try again.\n");
        }
    }

    return 0;
}

