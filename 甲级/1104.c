#include<stdio.h>
int main()
{
	int n;
	double a[100001];
	int i;
	double sum = 0;
	scanf("%d", &n);
	for (i = 0; i <n; i++)
	{
		scanf("%lf", &a[i]);
		sum += a[i] * (i+1)*(n - i);
	}
	printf("%.2lf", sum);
	return 0;
}
