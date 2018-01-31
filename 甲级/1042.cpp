#include<stdio.h>
#include<string.h>
#define max 54
//主要是找到将字符串与1-54对应的方法
int main()
{
	int num[54];
	int result[21][54];
	int i, j;
	char s[max+1][4];
	for (i = 1; i <= 13; i++)
	{
		if (i < 10) {
			s[i][0] = 'S';
			s[i][1] = '0'+i;
			s[i][2] = '\0';
		}
		else
		{
			s[i][0] = 'S';
			s[i][1] = '1';
			s[i][2] = '0'+i%10;
			s[i][3] = '\0';
		}
	}
	for (i = 1; i <= 13; i++)
	{
		if (i < 10)
		{
			s[13 + i][0] = 'H';
			s[13 + i][1] = '0'+i;
			s[13 + i][2] = '\0';
		}
		else
		{
			s[13 + i][0] = 'H';
			s[13 + i][1] = '1';
			s[13 + i][2] = '0'+i%10;
			s[13 + i][3] = '\0';
		}
	}
	for (i = 1; i <= 13; i++)
	{
		if (i < 10) {
			s[26 + i][0] = 'C';
			s[26 + i][1] = '0'+i;
			s[26 + i][2] = '\0';
		}
		else
		{
			s[26 + i][0] = 'C';
			s[26 + i][1] = '1';
			s[26 + i][2] = '0'+i%10;
			s[26 + i][3] = '\0';
		}
	}
	for (i = 1; i <= 13; i++)
	{
		if (i < 10) {
			s[39 + i][0] = 'D';
			s[39 + i][1] = '0'+i;
			s[39 + i][2] = '\0';
		}
		else
		{
			s[39 + i][0] = 'D';
			s[39 + i][1] = '1';
			s[39 + i][2] = '0'+i%10;
			s[39 + i][3] = '\0';
		}
	}
	s[53][0] = 'J';
	s[53][1] = '1';
	s[53][2] = '\0';
	s[54][0] = 'J';
	s[54][1] = '2';
	s[54][2] = '\0';
	int n;
	scanf("%d", &n);
	for(i=0;i<max;i++)
	    scanf("%d", &num[i]);
	for (i = 0; i < max; i++)
		result[0][i] = i;
	for (i = 1; i <= n; i++)
	{
		for (j = 0; j < max; j++)
			result[i][num[j]-1] = result[i - 1][j];
	}
	printf("%s", s[result[n][0] + 1]);
	for (i = 1; i < max; i++)
		printf(" %s", s[result[n][i] + 1]);
}