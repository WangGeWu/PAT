#include<stdio.h>
#include<string.h>
int main()
{
	int num[37] = {0};/*下标表示每一位的和，此下标内容表示每一位和为此下标数字的个数*/
	char s[5];
	int n;
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		int cnt = 0;
		scanf("%s", s);
		for (int j = 0; j < strlen(s); j++)
		{
			cnt += s[j] - '0';
		}
		num[cnt]++;
	}
	int cnt = 0;
	for (i = 0; i < 37; i++)
	{
		if (num[i] > 0)
			cnt++;
	}
	printf("%d\n", cnt);
	cnt = 0;
	for (i = 0; i < 37; i++)
	{
		if (num[i] > 0)
		{
			if (cnt == 0)
				printf("%d", i);
			else
				printf(" %d", i);
			cnt++;
		}
	}
	return 0;
}
