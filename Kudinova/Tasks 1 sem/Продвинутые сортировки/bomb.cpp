#include <stdio.h>

int main()
{
    char c = 0;

    int t = 0;
    int k = 0;

    while((c = getchar()) != EOF)
    {
        if((c < 'a') || (c > 'z') || (k == 0))
        {

            if(c == 'b')
            {
                if((c = getchar()) == 'o')
                {
                    if((c = getchar()) == 'm')
                    {
                        if((c = getchar()) == 'b')
                        {
                            c = getchar();
                            if((c < 'a') || (c > 'z'))
                            {
                                printf("YES");
                                t = 1;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    if(t == 0)
    {
        printf("NO");
    }
    return 0;
}
