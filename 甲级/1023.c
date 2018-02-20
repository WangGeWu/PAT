#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int flag_one[10];
int flag_two[10];
int cmp(char a[],char b[])
{
	int i;
	int alen = strlen(a);
	int blen = strlen(b);
	for (i=0; i < alen; i++)
		flag_one[a[i] - '0']++;
	for (i = 0; i < blen; i++)
		flag_two[b[i] - '0']++;
	i = 0;
	while (i < 10)
	{
		if (flag_one[i] != flag_two[i])
			return 0;
		i++;
	}
	return 1;
}
int main()
{
	char data_one[21];
	char data_two[21];
	for (int i = 0; i < 10; i++)
	{
		flag_one[i] = 0;
		flag_two[i] = 0;
	}
	//input
	int flag = 0;
	int num;
	gets_s(data_one, 21);
	for (int i = strlen(data_one)-1; i>=0;i--)
	{
		num=(data_one[i] - '0') * 2;
		data_two[i] = (num % 10 + flag)+'0';
		if (num >= 10)
			flag = 1;
		else flag = 0;
		if (i == 0 && flag == 1)
		{
			printf("No\n");
			printf("1");
			data_two[strlen(data_one)] = '\0';
			puts(data_two);
			return 0;
		}
	}
	data_two[strlen(data_one)] = '\0';
	//process
	if (cmp(data_one, data_two))
		printf("Yes\n");
	else
		printf("No\n");
	//output
	puts(data_two);
	return 0;
}
