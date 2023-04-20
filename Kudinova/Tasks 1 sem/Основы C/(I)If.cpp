#include <stdio.h>

int main()
{
    float x, y;

    scanf("%f %f", &x, &y);

    if (((y > -3 + x*x) && (y > 2)) || ((y < -3 + x*x) && (y < 2)))
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }

    return 0;
}
