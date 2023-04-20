unsigned long long fact(unsigned long long n)
{
    unsigned long long i, t;
    t = 1;
    for(i = 1; i <= n; i++)
    {
        t = t * i;
    }
    return t;
}
