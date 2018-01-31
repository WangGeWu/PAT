//动态规划
/*
  *flag[i][j]==1表示从i到j的子串为对称串
  *s[i] == s[j] : flag[i][j] = flag[i+1][j-1]
  *s[i] != s[j] : flag[i][j] =0
  *         边界  flag[i][i] = 1, flag[i][i+1] = (s[i] == s[i+1]) ? 1 : 0
*/
#include<stdio.h>
#include<string.h>
int flag[1001][1001];
int main()
{
	char s[1001];
	int i, j;
	int cnt = 1;
	gets_s(s, 1001);
	int len = strlen(s);
	//初始化
	for (i = 0; i < len; i++)
	{
		flag[i][i] = 1;
		if (s[i] == s[i + 1])
		{
			flag[i][i+1] = 1;
			cnt = 2;
		}
	}
	for (int k = 3; k <= len; k++)
	{
		for (i = 0; i < len - k + 1; i++)
		{
			j = i + k-1;
			if (flag[i + 1][j - 1] == 1 && s[i] == s[j])
			{
				flag[i][j] = 1;
				cnt = k;
			}
		}
	}
	printf("%d", cnt);
}