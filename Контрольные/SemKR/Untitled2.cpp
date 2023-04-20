#include <stdio.h>

struct Point {
    int x;
    int y;
};
struct Rect {
    struct Point lt; // left top
    struct Point rb; // right bottom
};

struct Rect * transform (const struct Rect * src) {
    int xleft = (src->lt).x;
    int xright = (src->rb).x;
    int ytop = (src->lt).y;
    int ybottom = (src->rb).y;

    struct Rect * rect = (struct Rect *)malloc(sizeof(struct Rect));
    (rect->lt).x = xright - 2 * (xright - xleft);
    (rect->lt).y = ybottom;
    (rect->rb).x = xleft;
    (rect->rb).y = ytop - 2 * (ytop - ybottom);

    return rect;
}

int main()
{
    struct Rect a = {{-1, 1}, {4, -2}};
    struct Rect * rect;
    rect = transform(&a);
    printf("%d %d %d %d\n", a.lt.x, a.lt.y, a.rb.x, a.rb.y);
    printf("%d %d %d %d\n", rect->lt.x, rect->lt.y, rect->rb.x, rect->rb.y);

    free(rect);

    return 0;
}
