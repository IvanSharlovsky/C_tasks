#include <stdio.h>

int main()
{
    int x = 0;
    int n = 0;

    scanf("%d", &x);
    scanf("%d", &n);

    int m[1000];

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &m[i]);
    }

    int num = 0;

    for(int i = 0; i < n; i++)
    {
        if (x == m[i])
        {
            num++;
        }
    }

    printf("%d", num);

    return 0;
}
