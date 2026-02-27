#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* create_node(int val) {
    Node *p = (Node*)malloc(sizeof(Node));
    if(!p) exit(1);
    p->data = val;
    p->next = NULL;
    return p;
}

int main() {
    int n;
    if(scanf("%d", &n)!=1) return 0;
    Node *head = NULL, *tail = NULL;
    for(int i=0;i<n;i++){
        int x;
        scanf("%d", &x);
        Node *node = create_node(x);
        if(!head) head = tail = node;
        else { tail->next = node; tail = node; }
    }
    int key;
    if(scanf("%d", &key)!=1) key = 0;
    Node *curr = head, *prev = NULL;
    while(curr){
        if(curr->data == key){
            if(prev) prev->next = curr->next;
            else head = curr->next;
            free(curr);
            break;
        }
        prev = curr;
        curr = curr->next;
    }
    Node *it = head;
    int first = 1;
    while(it){
        if(!first) printf(" ");
        printf("%d", it->data);
        first = 0;
        it = it->next;
    }
    printf("\n");
    while(head){
        Node *t = head;
        head = head->next;
        free(t);
    }
    return 0;
}