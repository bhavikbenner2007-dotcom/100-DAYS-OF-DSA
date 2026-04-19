#include <stdio.h>
#include <string.h>

#define MAX 100

int pq[MAX];   // priority queue array
int size = 0;  // current size of queue

// Insert element into priority queue
void insert(int x) {
    if (size == MAX) {
        return; // queue full
    }
    pq[size++] = x;
}

// Delete element with highest priority (smallest value)
int delete() {
    if (size == 0) {
        return -1; // queue empty
    }
    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (pq[i] < pq[minIndex]) {
            minIndex = i;
        }
    }
    int deleted = pq[minIndex];
    // Shift elements to fill the gap
    for (int i = minIndex; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }
    size--;
    return deleted;
}

// Peek element with highest priority (smallest value)
int peek() {
    if (size == 0) {
        return -1; // queue empty
    }
    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (pq[i] < pq[minIndex]) {
            minIndex = i;
        }
    }
    return pq[minIndex];
}

int main() {
    int N;
    scanf("%d", &N);

    char op[10];
    int x;

    for (int i = 0; i < N; i++) {
        scanf("%s", op);
        if (strcmp(op, "insert") == 0) {
            scanf("%d", &x);
            insert(x);
        } else if (strcmp(op, "delete") == 0) {
            printf("%d\n", delete());
        } else if (strcmp(op, "peek") == 0) {
            printf("%d\n", peek());
        }
    }

    return 0;
}
