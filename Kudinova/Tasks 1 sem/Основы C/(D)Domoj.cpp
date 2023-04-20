#include <stdio.h>

int main()
{
    int K = 0, N = 0;
    scanf ("%d %d", &K, &N);

    N = N % K;

    printf ("%d", N);
}
