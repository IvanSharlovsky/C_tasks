#include <stdio.h>

int main()
{
    int y;
    int x;
    int a[3][3];

    for (y = 0; y < 3; y ++)
    {
        for (x = 0; x < 3; x ++)
        {
            scanf("%d", & a[y][x]);
        }
    }

    for (y = 0; y < 3; y ++)
    {
        for (x = 0; x < 3; x ++)
        {
            printf("%d ", a[y][x]);
        }
        printf("\n");
    }

    return 0;
}
