#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int *a = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int k;
    scanf("%d", &k);
    if (n == 0) return 0;
    k = k % n;
    if (k < 0) k += n;
    int *b = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) b[(i + k) % n] = a[i];
    for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", b[i]);
    }
    printf("\n");
    free(a);
    free(b);
    return 0;
}