#include <stdio.h>

int main()
{
    int i = 0;
    int x;

    scanf("%d", &x);

    while(x > 0)
    {
        i = i + (x & 0x01);
        x = x >> 1;
    }

    printf("%d", i);

    return 0;
}
