#include<stdio.h>
int main()
{
	int i;
	int n;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		long long a, b, c, sum;
		scanf("%lld%lld%lld", &a, &b, &c);
		sum = a + b;
		if (sum <= 0 && a>0 && b > 0)//Òç³ö
			printf("Case #%d: true\n", i + 1);
		else if (sum >=0 && a < 0 && b < 0)//Òç³ö
			printf("Case #%d: false\n", i + 1);
		else
		{
			if (a + b > c)
				printf("Case #%d: true\n", i + 1);
			else
				printf("Case #%d: false\n", i + 1);
		}
	}
	return 0;
}