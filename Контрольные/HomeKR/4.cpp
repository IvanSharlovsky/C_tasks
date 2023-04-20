#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    int N = 0, i = 0;

    scanf("%d ", &N);

    char * simbols = (char*) malloc((N+2) * sizeof(char));

    for (i = 0; i < N; i++)
        simbols[i] = getchar();

    simbols[N+1] = 0;
    simbols[N+2] = '\0';

    unsigned long int a = strlen(simbols);

    printf("%lu",a);

    free(simbols);
}
