//一个点没AC
#include<stdio.h>
#include<string.h>
int main()
{
	int n;
	char s1[101];
	char s2[101];
	char res_s1[101];
	char res_s2[101];
	res_s1[0] = '0';
	res_s2[0] = '0';
	res_s1[1] = '.';
	res_s2[1] = '.';
	scanf("%d", &n);
	scanf("%s %s", s1, s2);
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int p = 0, q = 0;
	int cnt = 0;
	int flag = 0;
	int i, j = 0, k = 0;
	cnt = 0;
	int res1_cnt = 2;
	while (s1[k] == '0' && (s1[k] != '.'&& s1[k] != '\0'))k++;
	while (s2[j] == '0' && (s2[j] != '.'&& s2[j] != '\0'))j++;
	int cnt1 = 0;
	int cnt2 = 0;
	i = 0;
	while (s1[i] != '.'&&s1[i] != '\0')
	{
		i++;
		cnt1++;
	}
	i = 0;
	while (s2[i] != '.'&&s2[i] != '\0')
	{
		cnt2++;
		i++;
	}
	p = cnt1 - k;
	q = cnt2 - j;
	if (p == 0)
		i = k + 1;
	else i = k;
	while (s1[i] != '\0')
	{
		if (s1[i] != '.'&&cnt < n)
		{
			res_s1[res1_cnt++] = s1[i];
			cnt++;
		}
		i++;
	}
	for (i = res1_cnt; i < res1_cnt + n - cnt; i++)
	{
		res_s1[i] = '0';
	}
	res_s1[i] = '\0';
	cnt = 0;
	int res2_cnt = 2;
	if (q == 0)
		i = j + 1;
	else i = j;
	while (s2[i] != '\0')
	{
		if (s2[i] != '.'&&cnt < n)
		{
			res_s2[res2_cnt++] = s2[i];
			cnt++;
		}
		i++;
	}
	for (i = res2_cnt; i < res2_cnt + n - cnt; i++)
	{
		res_s2[i] = '0';
	}
	res_s2[i] = '\0';
	if (strcmp(res_s1, res_s2) == 0&&q==p)
	{
		printf("YES ");
		printf("%s*10^%d", res_s1, p);
	}
	else
	{
		printf("NO ");
		printf("%s*10^%d %s*10^%d", res_s1, p, res_s2, q);
	}
	return 0;
}