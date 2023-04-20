#include <stdio.h>
#include <string.h>
union u{
    char data[32];
    float f;
    double d;
    long double ld;
};

int main()
{
    union u a;
    char s[20];
    char s2[20];

    char f[20] = "float";
    char d[20] = "double";
    char ld[20] = "long";

    for(int i = 0; i < 32; i++)
    {
        a.data[i] = 0;
    }

    scanf("%s", s);
    int x;
    if(strcmp(s, f) == 0)
    {
        scanf("%f", &(a.f));
        x = sizeof(float);
    }

    if(strcmp(s, d) == 0)
    {
        scanf("%lg", &(a.d));
        x = sizeof(double);
    }

    if(strcmp(s, ld) == 0)
    {
        scanf("%s", s2);
        scanf("%Lf", &(a.ld));
        x = sizeof(long double);
    }

    for(int i = x - 1; i >= 0; i--){
        char c = a.data[i];

        for(int j = 1 << 7; j > 0; j = j >> 1){
            printf("%d", ((c & j) != 0)? 1 : 0);
            if(j == 1 << 4)
                printf(" ");
        }
        printf(" ");

    }

    return 0;
}
