#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* get (int n);
int print (int* a, int n);
int compare (int* a, int* b, int n, int m);
int sum (int* a, int* b, int n, int m);

int main () {
    int n = 0, m = 0;
    int *a, *b;

    scanf ("%d", &n);

    a = get (n);
    print (a, n);

    scanf("%d", &m);

    b = get (m);
    print (b, m);

    int comp = compare (a, b, n, m);
    printf ("The biggest is = %d of number\n", comp);

    int ressum = sum (a, b, n, m);
    printf ("Sum = %d\n", ressum);

    free (a);
    free (b);
}

int* get (int n) {
    int* p;
    p = (int*) calloc (n, sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &p[i]);

    return p;
}

int print (int* a, int n) {
    for (int i = 0; i < n; i++)
        printf ("%d", a[i]);

    printf ("\n");

    return 0;
}

int compare (int* a, int* b, int n, int m) {
    if (n == m) {
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > b [i]) {
                return 1;
                break;
            }

            else if (a[i] < b [i]) {
                return 2;
                break;
            }
        }

        if (a[n - 1] > b [n - 1])
            return 1;

        else if (a[n - 1] < b [n - 1])
            return 2;

        else return 0;
    }

    else if (n > m)
        return 1;

    else return 2;
}

int sum (int* a, int* b, int n, int m) {
    int s = 0;

    for(int i = n - 1; i >= 0; i--) {
        int st = pow (10, n - 1 - i);

        s += a[i] * st;

        printf ("%d\n", s);
    }

    for(int i = m - 1; i >= 0; i--) {
        int st = pow (10, m - i - 1);
        s += s + b[i] * st;
    }

    return s;
}
