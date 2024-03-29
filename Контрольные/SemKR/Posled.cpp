#include <stdio.h>
#include <stdlib.h>

int len (int N);
int rec (int K, int N);

int main()
{

    int K, N, RES;

    scanf("%d %d", &N, &K);

    RES = rec(K, N);

    printf("%c\n", RES + 'a' - 1);

    return 0;
}

int len(int N)
{
    int i, j = 1;

    for (i = 1; i < N; i++)
    {
        j = 2*j+1;
    }

    return j;
}

int rec (int K, int N)
{
    if (N == 1) {return 1;}
    if (K == 1) {return N;}
    if (K > len(N)/2 + 1)
    {
        return rec(K - len(N)/2 - 1, N - 1);
    }

    return rec(K - 1, N - 1);
}
