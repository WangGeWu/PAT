#include<stdio.h>
#include<stdlib.h>
int coin[1001];
int main()
{
	int v1, v2;
	int n, m;
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
	{
		int value;
		scanf("%d", &value);
		coin[value]++;
	}
	int flag;
	for (i = 0; i < 1001; i++)
	{
		flag = 0;
		if (coin[i])
		{
			flag = 1;
			coin[i]--;
			if (coin[m - i])
			{
				printf("%d %d", i, m - i);
				return 0;
			}
		}
		if (flag)
			coin[i]++;
	}
	printf("No Solution");
	return 0;
}
