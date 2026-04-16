#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
struct Node {
    int data;
    struct Node* next;
};

// Queue structure
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to initialize queue
void initQueue(struct Queue* q) {
    q->front = q->rear = NULL;
}

// Function to enqueue (insert at rear)
void enqueue(struct Queue* q, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

// Function to print queue elements
void printQueue(struct Queue* q) {
    struct Node* temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Queue q;
    initQueue(&q);

    int n, i, value;
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(&q, value);
    }

    printQueue(&q);

    return 0;
}
