#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a, const void *b)
{
	return *(int*)b - *(int*)a;
}
int main()
{
	int *a;
	int i;
	int n;
	scanf("%d", &n);
	a = (int*)malloc(sizeof(int)*(n + 1));
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	qsort(a + 1, n, sizeof(int), cmp);
	int ans = 0;
	i = 1;
	while (ans <= n&&a[i] > i)
	{
		ans++;
		i++;
	}
	printf("%d", ans);
	return 0;
}
