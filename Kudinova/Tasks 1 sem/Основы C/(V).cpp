int func_hyper(float x, float y)
{
    if(x <= -4)
    {
        return 0;
    }
    else
    {
        if((y >= ((1/(x+4)) - 3)) && (y >= -2))
        return 1;

        else
        return 0;
    }
}
