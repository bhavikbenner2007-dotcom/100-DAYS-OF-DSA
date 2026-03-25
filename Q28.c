#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create circular linked list
struct Node* createCircularList(int arr[], int n) {
    if (n == 0) return NULL;

    struct Node* head = NULL;
    struct Node* temp = NULL;
    struct Node* tail = NULL;

    for (int i = 0; i < n; i++) {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = arr[i];
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }
    // Make it circular
    tail->next = head;

    return head;
}

// Function to traverse and print circular linked list
void traverseCircularList(struct Node* head, int n) {
    if (head == NULL) return;

    struct Node* temp = head;
    for (int i = 0; i < n; i++) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* head = createCircularList(arr, n);

    traverseCircularList(head, n);

    return 0;
}