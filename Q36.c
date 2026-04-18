#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
struct Node {
    int data;
    struct Node* next;
};

// Circular Queue structure
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to initialize queue
void initQueue(struct Queue* q) {
    q->front = q->rear = NULL;
}

// Enqueue operation
void enqueue(struct Queue* q, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (q->front == NULL) {
        q->front = q->rear = newNode;
        q->rear->next = q->front; // circular link
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
        q->rear->next = q->front; // maintain circular link
    }
}

// Dequeue operation
void dequeue(struct Queue* q) {
    if (q->front == NULL) {
        return; // queue empty
    }

    if (q->front == q->rear) {
        free(q->front);
        q->front = q->rear = NULL;
    } else {
        struct Node* temp = q->front;
        q->front = q->front->next;
        q->rear->next = q->front; // maintain circular link
        free(temp);
    }
}

// Display queue elements
void display(struct Queue* q) {
    if (q->front == NULL) {
        return; // queue empty
    }

    struct Node* temp = q->front;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != q->front);
}

int main() {
    struct Queue q;
    initQueue(&q);

    int n, m, i, val;
    scanf("%d", &n);

    // Enqueue n elements
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(&q, val);
    }

    scanf("%d", &m);

    // Perform m dequeue operations
    for (i = 0; i < m; i++) {
        dequeue(&q);
    }

    // Print remaining elements
    display(&q);

    return 0;
}
