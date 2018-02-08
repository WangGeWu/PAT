#include<stdio.h>
#include<stdlib.h>
long num[100000];
int cmp(const void*a, const void *b)
{
	return *(long*)a > *(long*)b;
}
int main()
{
	long n,p;
	int i, j;
	scanf("%d%d", &n,&p);
	for (i = 0; i < n; i++)
		scanf("%d", &num[i]);
	qsort(num, n, sizeof(long), cmp);
	int length=1;
	int max = 0;
	for (i = 0; i < n; i++)
	{
		length = length - 1;
		for (j = i+length; j < n; j++)//下一次循环从i+length开始
		{
			if (num[i] * p >= num[j])
				length++;
			else break;
		}
		if (length > max)
			max = length;
	}
	printf("%d", max);
}