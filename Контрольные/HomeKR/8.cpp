#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    int n = 0, m = 0;
    int N;

    scanf("%d %d", &n, &m);

    N = n * m;

    int * matrix = (int *) malloc(N*sizeof(int));

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            scanf("%d", &matrix[i*m+k]);
        }
    }

    int * turn_matrix = (int *)malloc(N*sizeof(int));

    for (int i = 0; i < m; i++) {
        for(int k = 0; k < n; k++){
            turn_matrix[i*n + (n - k -1)] = matrix[k*m + i];
        }
    }

    for (int i = 0; i < m; i++) {
        for(int k = 0; k < n; k++){
            printf("%d ", turn_matrix[i*n + k]);
        }

        printf("\n");
    }

    free(matrix);
    free(turn_matrix);
}
