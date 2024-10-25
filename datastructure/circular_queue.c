#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int circularQueue[MAX], front = -1, rear = -1;

void enqueue() {
    int value;
    if ((front == 0 && rear == MAX - 1) || (rear + 1 == front))  {
        printf("Circular Queue is full..!\n");
    } else {
        printf("Enter the value to insert: ");
        scanf("%d", &value);
        if (front == -1) {  // First element insertion
            front = rear = 0;
        } else if (rear == MAX - 1 && front != 0) {
            rear = 0;  // Wrap around
        } else {
            rear++;
        }
        circularQueue[rear] = value;
        printf("%d is inserted into the circular queue.\n", value);
    }
}

void dequeue() {
    if (front == -1) {
        printf("Circular Queue is empty..!\n");
    } else {
        printf("%d is deleted from the circular queue.\n", circularQueue[front]);
        if (front == rear) {
            // Queue becomes empty
            front = rear = -1;
        } else if (front == MAX - 1) {
            front = 0;  // Wrap around
        } else {
            front++;
        }
    }
}

void displayqueue() {
    if (front == -1) {
        printf("Circular Queue is empty..!\n");
    } else {
        printf("Circular Queue elements are: ");
        if (rear >= front) {
            for (int i = front; i <= rear; i++)
                printf("%d\t", circularQueue[i]);
        } else {
            for (int i = 0; i <= rear; i++)
                printf("%d\t", circularQueue[i]);
            for (int i = front; i < MAX; i++)
                printf("%d\t", circularQueue[i]);

        }
        printf("\n");
    }
}

int main() {
    int choice;
    do {
        printf("\nCircular Queue Menu\n");
        printf("1. Insert into Circular Queue\n");
        printf("2. Delete from Circular Queue\n");
        printf("3. Display Circular Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                displayqueue();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice..!\n");
        }

    } while (1);

    return 0;
}