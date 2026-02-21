#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->data = x;
        newNode->next = NULL;
        if (head == NULL) head = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    Node *cur = head;
    int first = 1;
    while (cur) {
        if (!first) printf(" ");
        printf("%d", cur->data);
        first = 0;
        cur = cur->next;
    }
    printf("\n");
    return 0;
}