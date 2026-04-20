#include <stdio.h>
#define MAX 100

// Deque structure
struct Deque {
    int arr[MAX];
    int front;
    int rear;
};

// Initialize deque
void initDeque(struct Deque* dq) {
    dq->front = -1;
    dq->rear = -1;
}

// Check if empty
int isEmpty(struct Deque* dq) {
    return (dq->front == -1);
}

// Check if full
int isFull(struct Deque* dq) {
    return ((dq->front == 0 && dq->rear == MAX - 1) || (dq->front == dq->rear + 1));
}

// Insert at front
void push_front(struct Deque* dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full\n");
        return;
    }
    if (dq->front == -1) {
        dq->front = dq->rear = 0;
    } else if (dq->front == 0) {
        dq->front = MAX - 1;
    } else {
        dq->front--;
    }
    dq->arr[dq->front] = value;
}

// Insert at rear
void push_back(struct Deque* dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full\n");
        return;
    }
    if (dq->front == -1) {
        dq->front = dq->rear = 0;
    } else if (dq->rear == MAX - 1) {
        dq->rear = 0;
    } else {
        dq->rear++;
    }
    dq->arr[dq->rear] = value;
}

// Delete from front
void pop_front(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return;
    }
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else if (dq->front == MAX - 1) {
        dq->front = 0;
    } else {
        dq->front++;
    }
}

// Delete from rear
void pop_back(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return;
    }
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else if (dq->rear == 0) {
        dq->rear = MAX - 1;
    } else {
        dq->rear--;
    }
}

// Get front element
int front(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return -1;
    }
    return dq->arr[dq->front];
}

// Get rear element
int back(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return -1;
    }
    return dq->arr[dq->rear];
}

// Display deque
void display(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return;
    }
    int i = dq->front;
    while (1) {
        printf("%d ", dq->arr[i]);
        if (i == dq->rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    struct Deque dq;
    initDeque(&dq);

    push_back(&dq, 10);
    push_back(&dq, 20);
    push_front(&dq, 5);
    display(&dq);

    pop_front(&dq);
    display(&dq);

    pop_back(&dq);
    display(&dq);

    printf("Front: %d\n", front(&dq));
    printf("Back: %d\n", back(&dq));

    return 0;
}
