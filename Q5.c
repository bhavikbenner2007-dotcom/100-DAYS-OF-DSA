#include <stdio.h>
#include <stdlib.h>

int main() {
    int p, q;
    if (scanf("%d", &p) != 1) return 0;

    int *a = malloc(p * sizeof(int));
    for (int i = 0; i < p; ++i) scanf("%d", &a[i]);

    if (scanf("%d", &q) != 1) {
        free(a);
        return 0;
    }

    int *b = malloc(q * sizeof(int));
    for (int i = 0; i < q; ++i) scanf("%d", &b[i]);

    int i = 0, j = 0;
    int firstPrinted = 0;

    while (i < p || j < q) {
        int val;
        if (i < p && (j >= q || a[i] <= b[j])) {
            val = a[i++];
        } else {
            val = b[j++];
        }

        if (firstPrinted) {
            printf(" %d", val);
        } else {
            printf("%d", val);
            firstPrinted = 1;
        }
    }

    printf("\n");

    free(a);
    free(b);
    return 0;
}