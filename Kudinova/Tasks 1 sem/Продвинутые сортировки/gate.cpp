#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int power(int a, int b) {
    int p = 1;
    for (int j = 0; j < b; ++j) {
        p = p * a;
    }
    if (b == 0) {
        return 1;
    }
    return p;
}

int main() {
    char *s;
    s = (char*)malloc(100);
    char *k;
    k = (char*)malloc(100);
    scanf("%[^0123456789!] %[0123456789]", k, s);
    int x = 0, y = 0, m = 0;

    while (strcmp(k, "Treasure") != 0) {
        int p = strlen(s);
        for (int i = 0; i < p; ++i) {
            m = m + (s[i]-'0') * power(10, p - 1 - i);
        }
        switch (k[0]) {
            case 'W':
                x = x - m; break;
            case 'E':
                x = x + m; break;
            case 'N':
                y = y + m; break;
            case 'S':
                y = y - m; break;
            default:
                printf("ERROR!!");
        }
        scanf("%*c%[^0123456789!] %[0123456789]", k, s);
        m = 0;
    }
    printf("%d %d\n", x, y);
    free(k);
    free(s);
    return 0;
}
