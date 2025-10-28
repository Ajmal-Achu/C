#include <stdio.h> 
#include<stdlib.h> 
#include <stdbool.h> 
#define MAX 10 
int queue[MAX]; 
int rear = - 1; 
int front = -1; 
bool isEmpty() { 
return rear==front ; 
} 
bool isFull() { 
return rear == MAX - 1; 
} 
void enqueue() 
{ 
int item; 
if (isFull()) 
printf("Queue Overflow \n"); 
else 
{ 
printf("\nInset the element in queue : "); 
scanf("%d", &item); 
 rear = rear + 1; 
 queue[rear] = item; 
 } 
}  
void dequeue()  
{ 
if (isEmpty() ) 
    { 
    printf("\nQueue Underflow \n"); 
    return ; 
    } 
    else 
    { 
    front = front + 1; 
    printf("\nElement deleted from queue is : %d\n", queue[front]); 
    } 
}  
void display() 
{ 
int i; 
    if (isEmpty() ) 
        printf("\nQueue is empty \n"); 
    else 
    { 
        printf("\nQueue is : "); 
        for (i = front+1; i <= rear; i++) 
            printf("%d ", queue[i]); 
        printf("\n"); 
    } 
} 
 
int peek() { 
    if (isEmpty()) { 
        printf("Queue is empty. Nothing to peek.\n"); 
        return -1; // Error value 
    } else { 
        return queue[front+1]; 
    } 
} 

int size() { 
    if (isEmpty()) { 
        return 0; 
    } else { 
        return rear - (front + 1)+1; 
    } 
} 
int main() 
{ 
int choice; 
while (1) 
{ 
printf("\n1.Insert element to queue \n"); 
printf("2.Delete element from queue \n"); 
printf("3.Display all elements of queue \n"); 
printf("4.Peek \n"); 
printf("5.Size of the queue\n"); 
printf("6.Quit \n"); 
printf("\nEnter your choice : "); 
scanf("%d", &choice); 
switch (choice) 
{ 
case 1: 
    enqueue(); 
    break; 
case 2: 
    dequeue(); 
    break; 
case 3: 
    display(); 
    break; 
case 4: 
    int x=peek(); 
    if(x!=-1) printf("\nfront element is=%d\n",x); 
    break; 
case 5: 
    printf("\nsize of the queue is =%d\n",size()); 
    break; 
case 6: 
    exit(1); 
 
default: 
 
printf("\nWrong choice \n"); 
 
}
 
} 
return 0; 
}