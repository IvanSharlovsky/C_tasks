#include <stdio.h>

int main()
{
    int M = 0, N = 0, a[100000] = {0};

    scanf("%d %d", &M, &N);

    for(int i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }

    for(int i = N; i > 0; i--)
    {
        int ned = 0;

        for(int j = 0; j < i; j++)
        {
            if(a[j] < i)
                ned = ned + (i - a[j]);
        }

        if(ned <= M)
        {
            printf("%d", i);
            return 0;
        }
    }

    return 0;
}
