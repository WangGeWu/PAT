//两个测试点没AC
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char s[10000];
	int i = 0;
	scanf("%s", s);
	while (s[i] != '.')i++;
	int point = i;
	if (s[0] == '-')
		printf("-");
	while (s[i] != 'E')i++;
	int epoint = i;
	int num = atoi(s + i + 2);
	if (num == 0)
	{
		for (i = 1; i < epoint; i++)
			printf("%c", s[i]);
		return 0;
	}
	if (s[i + 1] == '+')
	{
		int cnt = 0;
		for (i = 1; i < epoint; i++)
		{
			if (s[i] != '.')
			{
				printf("%c", s[i]);
				cnt++;
			}
			if (cnt == num+1)
				printf(".");
		}
		for (i = 0; i < num - cnt+1; i++)
		{
			printf("0");
		}
		
	}
	else
	{
		printf("0.");
		for (i = 0; i < num - 1; i++)
			printf("0");
		for (i = 1; i < epoint; i++)
			if (s[i] != '.')
				printf("%c", s[i]);
	}
}