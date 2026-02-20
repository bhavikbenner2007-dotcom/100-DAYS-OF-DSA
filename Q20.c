#include <stdio.h>
#include <stdlib.h>

int cmp_ll(const void *a, const void *b) {
    long long va = *(const long long*)a;
    long long vb = *(const long long*)b;
    if (va < vb) return -1;
    if (va > vb) return 1;
    return 0;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    long long *pref = malloc((n + 1) * sizeof(long long));
    if (!pref) return 0;

    pref[0] = 0;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        sum += x;
        pref[i + 1] = sum;
    }

    qsort(pref, n + 1, sizeof(long long), cmp_ll);

    long long ans = 0;
    long long count = 1;
    for (int i = 1; i <= n; ++i) {
        if (pref[i] == pref[i - 1]) {
            ++count;
        } else {
            ans += (count * (count - 1)) / 2;
            count = 1;
        }
    }
    ans += (count * (count - 1)) / 2;

    printf("%lld\n", ans);

    free(pref);
    return 0;
}
