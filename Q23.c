#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* append(Node *head, int val) {
    Node *newn = (Node*)malloc(sizeof(Node));
    newn->data = val;
    newn->next = NULL;
    if (!head) return newn;
    Node *t = head;
    while (t->next) t = t->next;
    t->next = newn;
    return head;
}

Node* mergeSorted(Node *a, Node *b) {
    Node dummy;
    Node *tail = &dummy;
    tail->next = NULL;
    while (a && b) {
        if (a->data <= b->data) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }
    tail->next = a ? a : b;
    return dummy.next;
}

int main() {
    int n, m, val;
    if (scanf("%d", &n) != 1) return 0;
    Node *l1 = NULL;
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &val) != 1) val = 0;
        l1 = append(l1, val);
    }
    if (scanf("%d", &m) != 1) m = 0;
    Node *l2 = NULL;
    for (int i = 0; i < m; ++i) {
        if (scanf("%d", &val) != 1) val = 0;
        l2 = append(l2, val);
    }
    Node *merged = mergeSorted(l1, l2);
    int first = 1;
    for (Node *p = merged; p; p = p->next) {
        if (!first) printf(" ");
        printf("%d", p->data);
        first = 0;
    }
    printf("\n");
    Node *cur = merged;
    while (cur) {
        Node *tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    return 0;
}