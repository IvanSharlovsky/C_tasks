#include <stdio.h>

int main()
{
    int n = 0, m = 0;
    long int s = 0;

    scanf("%d", &n);

    for(m = 3; m <= n; m = m + 2)
    {
        s = s + ((m - 3) * m + 3) * 4 + (m - 1) * 6;
    }

    s++;

    printf("%ld", s);

    return 0;
}
