#include <stdio.h>
#include <math.h>

int main()
{
    double x = NAN, y = NAN;

    x = getchar();
    scanf ("%lf", &x);
    y = getchar();
    scanf ("%lf", &y);

    if ((fmod (x,4) >= 2) && (fmod (y,4) >= 2))
        printf ("Black");
    else printf ("White");
}
