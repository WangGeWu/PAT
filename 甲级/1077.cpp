#include<stdio.h>
#include<string.h>
char s[100][257];
int main()
{
	int n, i, j,k;
	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++)
	{
		gets_s(*(s + i), 257);
	}
	int len1 = strlen(s[0]);
	int cnt;
	int max = 999;
	for (i = 1; i < n; i++)
	{
		cnt = 0;
		k = len1 - 1;
		j = strlen(s[i]) - 1;
		while (s[i][j] == s[0][k]&&j>=0&&k>=0)
		{
			cnt++;
			k--; j--;
		}
		if (cnt < max)
		{
			max = cnt;
		}
		if (max == 0)
			break;
	}
	if (max == 0)
		printf("nai");
	else
	{
		printf("%s",s[0] + len1 - max);
	}
	return 0;
}