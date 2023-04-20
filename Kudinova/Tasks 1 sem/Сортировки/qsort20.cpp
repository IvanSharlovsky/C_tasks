#include<stdio.h>
#include<stdlib.h>

int comp(int * a, int * b){
	return *a - *b;
}


int main(){
	int i, n;
	scanf("%d", &n);
	int *q = (int *)malloc(sizeof(int) * n);
	for(i = 0; i < n; i++)
		scanf("%d", &q[i]);

	qsort (q, n, sizeof(int), (int(*)(const void *, const void *))comp);


	for(i = n - 1; i >= 0; i--)
		printf("%d ", q[i]);
	free(q);
	return 0;
}
