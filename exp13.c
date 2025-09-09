#include <stdio.h>
#include <stdlib.h>

#define MAX 5   // Size of the Queue

int queue[MAX];
int front = -1, rear = -1;
void enqueue(int val) {
    if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot insert %d\n", val);
        return;
    }
    if (front == -1) {
        front = 0; // First element
    }
    rear++;
    queue[rear] = val;
    printf("%d inserted into the queue.\n", val);
}
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! No elements to delete.\n");
        return;
    }
    printf("%d deleted from the queue.\n", queue[front]);
    front++;
}
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}
int main() {
    int choice, val;

    while (1) {
        printf("\n--- Queue Operations ---\n");
        printf("1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                dequeue();
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
