#include <stdio.h>

int main()
{
    int n = 0;
    int s1 = 0;
    int s2 = 0;

    scanf("%d", &n);
    int a[1000];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if ((i % 2) == 0)
        {
            s1 = s1 + a[i];
        }
        else if ((i % 2) == 1)
        {
            s2 = s2 + a[i];
        }
    }
    printf("%d", (s1 - s2));

    return 0;
}
