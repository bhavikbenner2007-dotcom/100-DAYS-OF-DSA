// Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.
#include <stdio.h>

int main() {
    int n, p , x;

   
    printf("Enter number of elements (n): ");
    scanf("%d", &n);

    
    int arr[n];

   
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
 
    printf("Enter element ");
    scanf("%d", &x);
    printf("Enter position ");
    scanf("%d", &p);


    if (p < 1 || p > n + 1) {
        printf("Invalid position! Must be between 1 and %d.\n", n + 1);
        return 1;
    }

    for (int i = n; i >= p; i--) {
        arr[i] = arr[i - 1];
    }

    arr[p - 1] = x;
    n++; 

    printf("Array after insertion:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}