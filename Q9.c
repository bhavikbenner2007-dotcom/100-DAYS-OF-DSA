#include <stdio.h>

int main(void) {
    char s[1001];
    if (scanf("%1000s", s) != 1) return 0;
    int i = 0;
    while (s[i]) i++;          
    while (i--) putchar(s[i]); 
    putchar('\n');
    return 0;
}