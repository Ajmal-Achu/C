#include <stdio.h>
#include <string.h>
int stack[50];
int top = -1;
void push(int x) { stack[++top] = x; }
int pop() { return stack[top--]; }
int main() {
    char postfix[50];
    int i, a, b, res;
    printf("Enter postfix expression: ");
    scanf("%s", postfix);
    for (i = 0; postfix[i] != '\0'; i++) {
        if (postfix[i] >= '0' && postfix[i] <= '9') {
            push(postfix[i] - '0');
        } else {
            b = pop(); a = pop();
            if (postfix[i] == '+') res = a + b;
            else if (postfix[i] == '-') res = a - b;
            else if (postfix[i] == '*') res = a * b;
            else if (postfix[i] == '/') res = a / b;
            push(res);
        }
    }
    printf("Result: %d\n", pop());
    return 0;
}
