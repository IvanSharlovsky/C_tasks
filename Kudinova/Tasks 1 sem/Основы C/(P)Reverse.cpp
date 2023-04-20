#include <stdio.h>

int main()
{
    int x = 0;
    int a = 0;
    int sum = 0;

    scanf("%d", &x);

    while (x > 0)
    {
        a = x % 10;
        sum = sum * 10 + a;
        x = x / 10;
    }

    printf("%d", sum);

    return 0;
}
