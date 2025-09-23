#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

int isFull() {
    return ((front == 0 && rear == SIZE - 1) || (front == rear + 1));
}

int isEmpty() {
    return (front == -1);
}

void enqueue(int item) {
    if (isFull()) {
        printf("Queue Overflow!\n");
        return;
    }
    if (front == -1) {
        front = 0;
        rear = 0;
    }
    else if (rear == SIZE - 1)
        rear = 0;
    else
        rear++;
    queue[rear] = item;
    printf("%d inserted\n", item);
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow!\n");
        return -1;
    }
    int item = queue[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else if (front == SIZE - 1)
        front = 0;
    else
        front++;
    return item;
}

int peek() {
    if (isEmpty()) {
        return -1;
    }
    return queue[front];
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    if (front <= rear) {
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    } else {
        for (int i = front; i < SIZE; i++)
            printf("%d ", queue[i]);
        for (int i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Check if Full\n");
        printf("6. Check if Empty\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                value = dequeue();
                if (value != -1)
                    printf("Deleted: %d\n", value);
                break;
            case 3:
                value = peek();
                if (value != -1)
                    printf("Front element: %d\n", value);
                else
                    printf("Queue is empty\n");
                break;
            case 4:
                display();
                break;
            case 5:
                if (isFull())
                    printf("Queue is FULL\n");
                else
                    printf("Queue is NOT full\n");
                break;
            case 6:
                if (isEmpty())
                    printf("Queue is EMPTY\n");
                else
                    printf("Queue is NOT empty\n");
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}