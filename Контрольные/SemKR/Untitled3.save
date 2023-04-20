int is_equal(Decimal * a, Decimal * b)
{
    if ((a->n - b->n) != 0)
    {
        return 0;
    }

    for (int i = a->n; i >= 0; —i)
    {
        if (((*(a->a + i) - '0') - (*(b->a + i) - '0')) != 0)
        {
            return 0;
        }
    }

    return 1;
}
