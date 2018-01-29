#include<stdio.h>
int Judge(int n)
{
	if (n <= 1)
		return -1;
	int i;
	for (i = 2; i*i < n; i++)
		if (n%i == 0)
			return -1;
	return 1;
}
int main()
{
	int n, d;
	int num[100];
	int i;
	int temp, x;
	while (scanf("%d",&n)==1&&n >= 0)
	{
		scanf("%d",&d);
		i = 0;
		if (Judge(n)>0)
		{
			while(n)
			{
				num[i++] = n%d;
				n = n / d;
			}
			temp = i;
			x = 0;
			for (i = 0; i < temp; i++)
			{
				x = x*d + num[i];
			}
			if (Judge(x)>0)
				printf("Yes\n");
			else
				printf("No\n");
		}
		else
			printf("No\n");
	}
	return 0;
}