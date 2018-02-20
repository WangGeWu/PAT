#include<stdio.h>
int prime[500000];
int main()
{
	long a;
	int i, j;
	//建立素数表
	for (i = 2; i*i <500000 ; i++)
		for (j = 2; i*j < 500000; j++)
			prime[i*j] = 1;//等于1表示i*j不是素数
	scanf("%ld", &a);
	if (a == 1)
	{
		printf("1=1");
		return 0;
	}
	printf("%d=",a);
	int cnt;
	for (i = 2; a >= 2; i++)
	{
		cnt = 0;
		while (a%i == 0 && prime[i] == 0)
		{
			cnt++;
			a = a / i;
		}
		if (a >= 2)
		{
			if (cnt == 1)
				printf("%d*", i);
			if (cnt >= 2)
				printf("%d^%d*", i, cnt);
		}
		else
		{
			if (cnt == 1)
				printf("%d", i);
			if (cnt >= 2)
				printf("%d^%d", i, cnt);
		}
	}
}
