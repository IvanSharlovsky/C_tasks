#include<stdio.h>
#include<stdlib.h>

int comp(const void *a, const void *b) {
    const double *ad, *bd;

    ad = (const double*)a;
    bd = (const double*)b;

    if (*ad < *bd)
    {
        return -1;
    }
    else if (*ad > *bd)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(){
	int i, n;
	scanf("%d", &n);
	double *q = (double *)malloc(sizeof(double) * n);
	for(i = 0; i < n; i++)
		scanf("%lg", &q[i]);

	qsort (q, n, sizeof(double), (int(*)(const void *, const void *))comp);


	for(i = 0; i < n; i++)
		printf("%lg ", q[i]);
	free(q);
	return 0;
}
