#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
} *head = NULL;
void insert(int x) {
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = x;
    new->next = NULL;
    if (head == NULL) head = new;
    else {
        struct node *temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = new;
    }
    printf("%d inserted\n", x);
}
void delete(int x) {
    if (head == NULL) {
        printf("List empty\n");
        return;
    }
    struct node *temp = head, *prev = NULL;
    if (head->data == x) {
        head = head->next;
        free(temp);
        printf("%d deleted\n", x);
        return;
    }
    while (temp != NULL && temp->data != x) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) printf("Not found\n");
    else {
        prev->next = temp->next;
        free(temp);
        printf("%d deleted\n", x);
    }
}
void display() {
    if (head == NULL) printf("List empty\n");
    else {
        struct node *temp = head;
        printf("List: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main() {
    int x, ch;
    while (1) {
        printf("1. Insert 2. Delete 3. Display 4. Exit: ");
        scanf("%d", &ch);
        if (ch == 1) {
            printf("Enter value: ");
            scanf("%d", &x);
            insert(x);
        } else if (ch == 2) {
            printf("Enter value to delete: ");
            scanf("%d", &x);
            delete(x);
        } else if (ch == 3) display();
        else break;
    }
    return 0;
}
