#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	int i, j, k;
	scanf("%d", &n);
	int m = sqrt(n);
	int len = 12;
	for (i = 12; i > 0; i--)//Ã¶¾Ù
		for (j = 2; j <= m; j++)
		{
			long long ans = 1;
			for (k = j; k - j +1<= i; k++)
			{
				ans *= k;
			}
			if (n%ans == 0) {
				printf("%d\n", i);
				printf("%d", j);
				for (int p = j + 1; p - j+1 <= i; p++)
				{
					printf("*%d", p);
				}
				return 0;
			}
		}
	printf("1\n%d",n);
	return 0;
}