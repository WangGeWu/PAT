#include<stdio.h>
#include<stdlib.h>
int a[100000];
int b[100000];
int c[100000];
int cmp(const void*a, const void *b)
{
	return *(int*)a - *(int*)b;
}
int main()
{
	int i, j;
	int n;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	qsort(b, n, sizeof(int), cmp);
	int max = 0;
	int cnt = 0;
	for (i = 0; i < n; i++)
	{
		if (a[i] == b[i] && a[i] > max)
		{
			c[cnt++] = a[i];
		}
		if (a[i] > max)
			max = a[i];
	}
	printf("%d\n", cnt);
	if (cnt != 0)
	{
		printf("%d", c[0]);
		for (i = 1; i < cnt; i++)
			printf(" %d", c[i]);
	}
	else
		printf("\n");
	return 0;
}
