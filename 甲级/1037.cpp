#include<stdio.h>
#include<stdlib.h>
//贪心算法
int cmp(const void *a, const void *b)
{
	return (*(int*)a) - (*(int*)b);
}
int main()
{
	int n, m;
	int i;
	//input
	scanf("%d", &n);
	int *coupon = (int*)malloc(n*sizeof(int));
	for (i = 0; i < n; i++)
		scanf("%d", &coupon[i]);
	scanf("%d", &m);
	int *product = (int*)malloc(m * sizeof(int));
	for (i = 0; i < m; i++)
		scanf("%d", &product[i]);
	//process
	qsort(coupon, n, sizeof(int), cmp);
	qsort(product, m, sizeof(int), cmp);
	i = 0;
	int value=0;
	while (coupon[i] < 0 && product[i] < 0)
	{
		value += coupon[i] * product[i];
		i++;
	}
	int j = m - 1;
	i = n - 1;
	while (coupon[i] > 0 && product[j] > 0)
	{
		value += coupon[i] * product[j];
		i--; j--;
	}
	printf("%d\n", value);
}
