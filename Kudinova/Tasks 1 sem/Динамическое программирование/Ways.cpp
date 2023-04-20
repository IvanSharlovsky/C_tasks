#include <stdio.h>

int main()
{
    int n, m, biggest;

    scanf("%d %d", &n, &m);

    if (n > m)
        biggest = n;

    else
        biggest = m;

    unsigned long long int net[100][100];

    for(int i = 0; i < biggest + 1; i++)
    {
        net[i][0] = 1;
        net[0][i] = 1;
    }

    for(int i = 1; i < biggest + 1; i++)
    {
        for(int k = 1; k < biggest + 1; k++)
        {
            net[i][k] = net[i - 1][k] + net[i][k - 1];
        }
    }

    printf("%llu", net[n][m]);

    return 0;
}
