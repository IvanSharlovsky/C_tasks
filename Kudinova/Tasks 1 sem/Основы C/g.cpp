#include <stdio.h>

int x;
int y, z;

int main()
{
    scanf("%d %d %d", &x, &y, &z);
    int d;
    x = x + z;
    y = y + z;
    if(x > y)
    {
        d = x - y;
        printf("%d %d %d", d, y, x);
    }
    else
    {
        d = y - x;
        printf("%d %d %d", d, x, y);
    }

    return 0;
}
