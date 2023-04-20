#include <stdio.h>
#include <stdlib.h>

int main()
{
    int h1 = 0, h2 = 0, m1 = 0, m2 = 0;

    scanf("%d:%d", &h1, &m1);
    scanf("%d:%d", &h2, &m2);

    int OSTm = (m1 + m2) % 60;

    int SUMh = h1 + h2 + (m1 + m2) / 60;

    int end = SUMh % 24;

    printf("%.2d:", end);

    printf("%.2d", OSTm);

    return 0;
}
