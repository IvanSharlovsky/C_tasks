#include <stdio.h>


int main()
{
    float x, y;

    scanf("%f %f", &x, &y);

    if ((y >= 1 + x*x) || (y <= -2 - x*x))
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }

    return 0;
}
