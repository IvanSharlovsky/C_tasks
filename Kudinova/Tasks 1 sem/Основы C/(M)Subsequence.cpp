#include <stdio.h>

int main()
{
    int n = 0;

    scanf("%d", &n);

    int a[30];

    a[0] = a[1] = a[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        a[i] = a[i - 1] + a[i - 2] + a[i - 3];
    }

    printf("%d", a[n]);

    return 0;
}
