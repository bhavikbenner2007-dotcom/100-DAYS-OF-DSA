#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int a[n];
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &a[i]) != 1) return 0;
    }

    printf("%d", a[0]);
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[i-1]) {
            printf(" %d", a[i]);
        }
    }
    printf("\n");
    return 0;
}