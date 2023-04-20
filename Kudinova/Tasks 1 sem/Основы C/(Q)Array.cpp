#include <stdio.h>

int main()
{
    int a[5];

    scanf("%d", &a[0]);
    scanf("%d", &a[1]);
    scanf("%d", &a[2]);

    a[3] = 7;
    a[4] = a[0];

    printf("%d\n%d\n%d\n", a[0], a[3], a[4]);

    return 0;
}
