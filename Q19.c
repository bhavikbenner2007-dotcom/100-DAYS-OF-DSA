/* Given an array of integers, find two elements whose sum is closest to zero.*/
#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int *a = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int min_sum = abs(a[0] + a[1]);
    int x = a[0], y = a[1];
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = abs(a[i] + a[j]);
            if (sum < min_sum) {
                min_sum = sum;
                x = a[i];
                y = a[j];
            }
        }
    }
    printf("%d %d\n", x, y);
    free(a);
    return 0;
}       

