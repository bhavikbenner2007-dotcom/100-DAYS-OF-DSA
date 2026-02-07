#include <stdio.h>

long long fib(int n) {
    if (n == 0) return 0;      // base case
    if (n == 1) return 1;      // base case
    return fib(n - 1) + fib(n - 2); // recursive step
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    printf("%lld\n", fib(n));
    return 0;
}