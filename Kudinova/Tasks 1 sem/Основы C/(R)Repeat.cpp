#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0;

    scanf("%d", &n);

    int *p;

    p = (int *)malloc(sizeof(int) * n);

    int i = 0;

    for(i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }

    for(i = 0; i < n; i++)
    {
        printf("%d ", p[i]);
    }

    for(i = 0; i < n; i++)
    {
        printf("%d ", p[i]);
    }

    free(p);

    return 0;

}
