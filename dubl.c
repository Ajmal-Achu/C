#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int deque[SIZE];
int front = -1, rear = -1;

int isFull() {
    return ((front == 0 && rear == SIZE - 1) || (front == rear + 1));
}

int isEmpty() {
    return (front == -1);
}

void insertFront(int item) {
    if (isFull()) {
        printf("Deque Overflow!\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    }
    else if (front == 0) {
        front = SIZE - 1;
    }
    else {
        front--;
    }
    deque[front] = item;
    printf("%d inserted at front\n", item);
}

void insertRear(int item) {
    if (isFull()) {
        printf("Deque Overflow!\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    }
    else if (rear == SIZE - 1) {
        rear = 0;
    }
    else {
        rear++;
    }
    deque[rear] = item;
    printf("%d inserted at rear\n", item);
}

int deleteFront() {
    if (isEmpty()) {
        printf("Deque Underflow!\n");
        return -1;
    }
    int item = deque[front];
    if (front == rear) {
        front = rear = -1;
    }
    else if (front == SIZE - 1) {
        front = 0;
    }
    else {
        front++;
    }
    return item;
}

int deleteRear() {
    if (isEmpty()) {
        printf("Deque Underflow!\n");
        return -1;
    }
    int item = deque[rear];
    if (front == rear) {
        front = rear = -1;
    }
    else if (rear == 0) {
        rear = SIZE - 1;
    }
    else {
        rear--;
    }
    return item;
}

void display() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque: ");
    int i = front;
    if (front <= rear) {
        while (i <= rear) {
            printf("%d ", deque[i]);
            i++;
        }
    } else {
        while (i < SIZE) {
            printf("%d ", deque[i]);
            i++;
        }
        i = 0;
        while (i <= rear) {
            printf("%d ", deque[i]);
            i++;
        }
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Double Ended Queue (Deque) Menu ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display\n");
        printf("6. Check if Full\n");
        printf("7. Check if Empty\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertFront(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertRear(value);
                break;
            case 3:
                value = deleteFront();
                if (value != -1)
                    printf("Deleted from front: %d\n", value);
                break;
            case 4:
                value = deleteRear();
                if (value != -1)
                    printf("Deleted from rear: %d\n", value);
                break;
            case 5:
                display();
                break;
            case 6:
                if (isFull())
                    printf("Deque is FULL\n");
                else
                    printf("Deque is NOT full\n");
                break;
            case 7:
                if (isEmpty())
                    printf("Deque is EMPTY\n");
                else
                    printf("Deque is NOT empty\n");
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}