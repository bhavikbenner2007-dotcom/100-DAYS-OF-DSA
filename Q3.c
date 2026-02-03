#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int a[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    int k;
    scanf("%d", &k);

    int comparisons = 0;
    for (int i = 0; i < n; ++i) {
        comparisons++;
        if (a[i] == k) {
            printf("Found at index %d\n", i);
            printf("Comparisons = %d\n", comparisons);
            return 0;
        }
    }

    printf("Not Found\n");
    printf("Comparisons = %d\n", comparisons);
    return 0;
}