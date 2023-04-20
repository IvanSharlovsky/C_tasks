int foo2(int * px, int * py)
{
    int res;
    res = (*px) + (*py);
    (*px)++;
    --(*py);
    printf("foo2 : res=%d x=%d y=%d\n", res, (*px), (*py));
    return res;
}
