#include <stdio.h>

int main()
{
    int y = 0;
    int x = 0;
    int a[3][3];
    int sum = 0;

    for (y = 0; y < 3; y ++)
    {
        for (x = 0; x < 3; x ++)
        {
            scanf("%d", & a[y][x]);
        }
    }

    sum = a[1][1] + a[2][2] + a[0][0];

    printf("%d", sum);

    return 0;
}
