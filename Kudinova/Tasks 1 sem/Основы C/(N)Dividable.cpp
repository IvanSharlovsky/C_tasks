#include <stdio.h>

int main()
{
    int c = 0;
    unsigned long long int sum = 0;

    c = getchar();

    while(c != '\n')
    {
        sum = sum + (c - '0');
        c = getchar();
    }

    if ((sum % 3) == 0)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }

    return 0;
}
