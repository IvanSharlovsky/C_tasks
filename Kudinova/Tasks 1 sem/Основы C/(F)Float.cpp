#include <stdio.h>

int main()
{
    double x1, y1, x2, y2, x3, y3;

    scanf("%lg %lg %lg %lg %lg %lg", &x1, &y1, &x2, &y2, &x3, &y3);

    double xm, ym;

    xm = (x1 + x2 + x3) / 3;
    ym = (y1 + y2 + y3) / 3;

    printf("%lg %lg", xm, ym);

    return 0;
}
