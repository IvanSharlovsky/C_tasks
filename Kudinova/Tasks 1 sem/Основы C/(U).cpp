#include <stdio.h>

float sv(float a)
{
    float kv = a * a;
    return kv;
}
int main()
{
    float a, k;
    scanf("%f", &a);
    k = sv(a);
    printf("%f\n", k);
    return 0;
}
