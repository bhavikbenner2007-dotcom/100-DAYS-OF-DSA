#include <stdio.h>

int power(int a, int b) {
    if (b == 0) return 1;
    return a * power(a, b - 1);
}

int main() {
    int a, b;
    if (scanf("%d %d", &a, &b) != 2) return 0;
    if (b < 0) {
        printf("Negative exponent not supported\n");
        return 0;
    }
    printf("%d\n", power(a, b));
    return 0;
}