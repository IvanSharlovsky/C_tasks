unsigned int nod(unsigned int a, unsigned int b)
{
    unsigned nod = 0;

    for(nod = (a < b)? a : b; nod > 0; nod--)
        if (!(b % nod || a % nod))
            break;
    return nod;
}
