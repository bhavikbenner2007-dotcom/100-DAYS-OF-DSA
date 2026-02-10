#include <stdio.h>
#include <string.h>

int main(void) {
    char s[1001];                 
    if (fgets(s, sizeof s, stdin) == NULL) return 0;

   
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
        len--;
    }

    int i = 0;
    int j = (int)len - 1;
    int is_pal = 1;              

    while (i < j) {
        if (s[i] != s[j]) {
            is_pal = 0;
            break;
        }
        i++;
        j--;
    }

    if (is_pal) printf("YES\n");
    else printf("NO\n");

    return 0;
}