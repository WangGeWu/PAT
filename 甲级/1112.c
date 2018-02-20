#include<stdio.h>
#include<string.h>
int main()
{
	int hash[257] = { 0 };
	int flag[257] = { 0 };
	int k;
	int i,j;
	char s[1001];
	scanf("%d", &k);
	scanf("%s", s);
	for (i = 0; i <= strlen(s) - k; i++)
	{
		for (j = i + 1; j <= i + k - 1; j++)
		{
			if (s[i] != s[j])
			{
				flag[s[i]] = 1;
				break;
			}
		}
		if (flag[s[i]] == 0)
			i=i + k - 1;
	}
	for (i = 0; i <= strlen(s)-k; i++)
	{
		if (flag[s[i]] == 0&&hash[s[i]]==0)
		{
			hash[s[i]] = 1;
			printf("%c", s[i]);
		}
	}
	printf("\n");
	for (i = 0; i < strlen(s); i++)
	{
		printf("%c", s[i]);
		if (flag[s[i]] == 0)
			i = i + k - 1;
	}
	return 0;
}
