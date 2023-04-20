///////////////////////////////////////////////////////////////
//Изменил условие задачи: # = 1, так чуть проще но смысл тот же
///////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#define sof SizeOfField
#define f Field

int main () {

    int m = 0, n = 0, SizeOfField = 0;

    scanf ("%d %d", &n, &m);

    sof = n*m;

    int * f = (int *)calloc(sof, sizeof(int));

    for (int i = 0; i < sof; i++)
        scanf ("%d", &f[i]);

    if (f[0] == 0)
        f[0] = 1;

    else
        f[0] = 0;

    for (int i = 1; i < sof; i++) {

        if (f[i] == 1) {

            f[i] = 0;

            continue;
        }

        if (i < m) {

            f[i] = f[i-1];

            continue;
        }

        if ((i%m) == 0) {

            f[i] = f[i - m];

            continue;
        }

        f[i] = f[i-1] + f[i-m];
    }

    printf ("\n%d ", f[sof - 1]);

    free (f);
}
