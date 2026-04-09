#include <stdio.h>

#define MAX 100   // maximum size of stack

int stack[MAX];
int top = -1;

// Function to push an element onto the stack
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = value;
    }
}

// Function to pop an element from the stack
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        top--;
    }
}

// Function to display stack elements from top to bottom
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int n, m, value;

    // Input number of elements to push
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        push(value);
    }

    // Input number of pops
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        pop();
    }

    // Print remaining stack
    display();

    return 0;
}
