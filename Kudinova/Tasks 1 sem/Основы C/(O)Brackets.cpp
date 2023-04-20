#include <stdio.h>

int main()
{
    char c = 0, t = 0;
    int x = 0;

    c = getchar();
    if (c == ')')
    {
        printf("NO");
        return 0;
    }
    else
    {
        x ++;
        while((c = getchar()) != '\n')
        {

            if (c == '(')
            {
                x ++;
            }

            if (c == ')')
            {
                x --;
            }
            t = c;

        }
    }
    if (t == '(')
    {
        printf("NO");
        return 0;
    }

    if (x == 0)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }

    return 0;
}
