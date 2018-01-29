#include<stdio.h>
#include<stdlib.h>
long num[2000000];
int cmp(const void *a, const void *b)
{
	return *((long*)a) - *((long*)b);
}
int main()
{
	//long num[2000000]
	int m, n;
	int i;
	scanf("%d", &m);
	for (i = 0; i < m; i++)
		scanf("%ld", &num[i]);
	scanf("%d", &n);
	for (; i < m + n; i++)
		scanf("%ld", &num[i]);
	qsort(num,m+n,sizeof(long),cmp);
	printf("%d", num[(m + n - 1) / 2]);
	return 0;
}