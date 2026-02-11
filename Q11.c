#include <stdio.h>

int main() {
    int m, n;
    int a[100][100], b[100][100], sum[100][100];
    int i, j;

    // Read dimensions
    if (scanf("%d %d", &m, &n) != 2) return 0;

    // Read first matrix
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Read second matrix
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    // Compute sum
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }

    // Print result
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (j) printf(" ");
            printf("%d", sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}