#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to build linked list from array
struct Node* buildList(int arr[], int n) {
    if (n == 0) return NULL;
    struct Node* head = createNode(arr[0]);
    struct Node* temp = head;
    for (int i = 1; i < n; i++) {
        temp->next = createNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

// Count length of linked list
int getLength(struct Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

// Find intersection point
struct Node* getIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    // Advance longer list
    if (len1 > len2) {
        for (int i = 0; i < diff; i++) head1 = head1->next;
    } else {
        for (int i = 0; i < diff; i++) head2 = head2->next;
    }

    // Traverse together
    while (head1 && head2) {
        if (head1 == head2) return head1; // Intersection found
        head1 = head1->next;
        head2 = head2->next;
    }
    return NULL;
}

int main() {
    int n, m;
    scanf("%d", &n);
    int arr1[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr1[i]);

    scanf("%d", &m);
    int arr2[m];
    for (int i = 0; i < m; i++) scanf("%d", &arr2[i]);

    struct Node* head1 = buildList(arr1, n);
    struct Node* head2 = buildList(arr2, m);

    struct Node* intersection = getIntersection(head1, head2);

    if (intersection)
        printf("%d\n", intersection->data);
    else
        printf("No Intersection\n");

    return 0;
}