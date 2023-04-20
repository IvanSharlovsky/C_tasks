#include <stdio.h>

int main()
{
    unsigned long long x, y;
    int c = 0;

    scanf("%llu %llu", &x, &y);

    for (int i = 0; i < 1000; i++)
    {
        if (x % 2 != y % 2)
        {
            c++;
        }

        y = y >> 1;
        x = x >> 1;
    }

    printf("%d", c);

    return 0;
}
