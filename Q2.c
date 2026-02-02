#include <stdio.h>

int main(void) {
    int n, pos;
    if (scanf("%d", &n) != 1) return 0;

    int a[100];
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    if (scanf("%d", &pos) != 1) return 0;
    pos = pos - 1; // convert to 0-based index

    if (pos < 0 || pos >= n) { // invalid position: print original array
        for (int i = 0; i < n; ++i) {
            if (i) printf(" ");
            printf("%d", a[i]);
        }
        return 0;
    }

    for (int i = pos; i < n - 1; ++i) a[i] = a[i + 1];

    for (int i = 0; i < n - 1; ++i) {
        if (i) printf(" ");
        printf("%d", a[i]);
    }
    return 0;
}