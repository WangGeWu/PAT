#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}
int main()
{
	int n;
	scanf("%d", &n);
	int *a = (int*)malloc(sizeof(int)*n);
	int i;
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	qsort(a, n, sizeof(int), cmp);
	float len = 0;
	a[1] += a[0];
	for (i = 1; i < n; i++)
	{
		len = len / 2 + a[i];
	}
	printf("%d", (int)(len / 2));
	return 0;
}
