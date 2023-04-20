struct Rect * transform (const struct Rect * src)
{
    int x1, y1, x2, y2;

    x1 = (src->lt).x;
    y1 = (src->lt).y;
    x2 = (src->rb).x;
    y2 = (src->rb).y;

    struct Rect * rect = (struct Rect *)malloc(sizeof(struct Rect));

    (rect->lt).x = x2 - y1 + y2;
    (rect->lt).y = y2;
    (rect->rb).x = x2;
    (rect->rb).y = y2 - x2 + x1;

    return rect;
}
