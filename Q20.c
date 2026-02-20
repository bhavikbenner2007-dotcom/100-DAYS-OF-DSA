#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n < 2) return 0;

    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);

    qsort(arr, n, sizeof(int), cmp);

    int left = 0, right = n - 1;
    int bestA = arr[0], bestB = arr[1];
    int bestAbsSum = INT_MAX;

    while (left < right) {
        int sum = arr[left] + arr[right];
        int absSum = abs(sum);
        if (absSum < bestAbsSum) {
            bestAbsSum = absSum;
            bestA = arr[left];
            bestB = arr[right];
        }
        if (sum > 0) right--;
        else if (sum < 0) left++;
        else break; // sum == 0 is optimal
    }

    printf("%d %d\n", bestA, bestB);
    free(arr);
    return 0;
}