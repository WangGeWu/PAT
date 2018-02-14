#include<stdio.h>
#include<stdlib.h>
int a[100000];
int cmp(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}
int main()
{
	int n;
	int i, j;
	scanf("%d", &n);
	int allsum = 0, leftsum = 0, rightsum = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		allsum += a[i];
	}
	qsort(a, n, sizeof(n), cmp);
	for (i = 0; i < n / 2; i++)
		leftsum += a[i];
	rightsum = allsum - leftsum;
	printf("%d %d",n-n/2-n/2,rightsum - leftsum);
	return 0;
}