int in_region(struct Point p)
{
    float x, y;

    x = p.x;
    y = p.y;



    if((y > -2) && (y < x + 4) && (y > 1/(x + 4) - 3))
        return 1;
    else
        return 0;
}
