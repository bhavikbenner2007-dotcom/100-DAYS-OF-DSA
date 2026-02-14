#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int val;
    int isIdentity = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (scanf("%d", &val) != 1) val = 0;
            if (i == j) {
                if (val != 1) isIdentity = 0;
            } else {
                if (val != 0) isIdentity = 0;
            }
        }
    }

    if (isIdentity)
        printf("Identity Matrix\n");
    else
        printf("Not an Identity Matrix\n");

    return 0;
}