#include <stdio.h> 
#include <stdlib.h> 
int *queue; 
int front = -1, rear = -1, size; 
int isFull() { 
    return ((rear + 1) % size == front); 
} 
int isEmpty() { 
    return (front == -1); 
} 
void enqueue(int value) { 
    if (isFull()) { 
        printf("Queue Overflow  Cannot insert %d\n", value); 
        return; 
    } 
 
    if (isEmpty()) { 
        front = rear = 0; 
    } else { 
        rear = (rear + 1) % size; 
    } 
 
    queue[rear] = value; 
    printf("Inserted %d\n", value); 
} 
void dequeue() { 
    if (isEmpty()) { 
        printf("Queue Underflow Cannot dequeue\n"); 
        return; 
    } 
    int deletedValue = queue[front]; 
 
    if (front == rear) { 
        front = rear = -1; 
    } else { 
        front = (front + 1) % size; 
    } 
    printf("Deleted %d\n", deletedValue); 
}
void display() { 
    if (isEmpty()) { 
        printf("Queue is empty\n"); 
        return; 
    } 
    printf("Queue elements: "); 
    int i = front; 
    while (1) { 
        printf("%d ", queue[i]); 
        if (i == rear) 
            break; 
        i = (i + 1) % size; 
    } 
    printf("\n"); 
} 
int main() { 
    int choice, value; 
    printf("Enter the size of the circular queue: "); 
    scanf("%d", &size); 
 
    if (size <= 0) { 
        printf("Invalid size Exiting.\n"); 
        return 1; 
    } 
    queue = (int *)malloc(size * sizeof(int)); 
    if (queue == NULL) { 
        printf("Memory allocation failed\n"); 
        return 1; 
    } 
    while (1) { 
        printf("\n--- Circular Queue Menu ---\n"); 
        printf("1. Enqueue (Insert)\n2. Dequeue (Delete)\n3. Display\n4. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                printf("Enter value to insert: "); 
                scanf("%d", &value); 
                enqueue(value); 
                break; 
 
            case 2: 
                dequeue(); 
                break; 
 
            case 3: 
                display(); 
                break; 
 
            case 4: 
                printf("Exiting program.\n"); 
                free(queue); 
                return 0; 
 
            default:
                printf("Invalid choice Please try again.\n"); 
        } 
    } 
 
    return 0; 
}