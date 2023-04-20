#include <stdio.h>
#include <stdlib.h>

int main() {
    int m1 = 0, n1 = 0, m2 = 0, n2 = 0;
    int a[100][100];
    int b[100][100];
    int c[100][100];
    scanf("%d %d %d %d", &m1, &n1, &m2, &n2);

    if (n1 != m2) {
        printf("%d", -1);
        return 0;
    }

    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < m2; i++) {
        for (int j = 0; j < n2; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    int s = 0;

    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n2; j++) {
            for (int k = 0; k < n1; k++) {
                s = s + a[i][k] * b[k][j];
            }

            c[i][j] = s;
            s = 0;
        }
    }

    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n2; j++) {
        printf("%d ", c[i][j]);
        }
    }

    return 0;
}
