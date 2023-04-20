#include <stdio.h>
#include <math.h>

int dx, dy;

struct Line
{
    int x1, x2, y1, y2;
};

struct Scift
{
    int dx, dy;
};

int main()
{
    struct Line num;
    struct Scift s;
    scanf("%d %d %d %d/n", &num.x1, &num.y1, &num.x2, &num.y2);
    scanf("%d %d", &s.dx, &s.dy);
    double d;
    num.x1 = num.x1 + s.dx;
    num.y1 = num.y1 + s.dy;
    num.x2 = num.x2 + s.dx;
    num.y2 = num.y2 + s.dy;

    d = sqrtf((num.x1 - num.x2)*(num.x1 - num.x2) + (num.y1 - num.y2)*(num.y1 - num.y2));

    printf("%lg\n", d);
    printf("%d %d %d %d", num.x1, num.y1, num.x2, num.y2);

    return 0;
}
