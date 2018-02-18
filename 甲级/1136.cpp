#include<stdio.h>
#include<string.h>
int judge(char s[],int x)
{
	int i;
	for (i = x; i < strlen(s+x)/2+x; i++)
	{
		if (s[i] != s[strlen(s) - 1 - (i-x)])
			return 0;
	}
	return 1;
}
int main()
{
	char stra[1020];
	char strb[1020];
	char strc[1020];
	int i;
	for (i = 0; i < 10; i++)
		stra[i]=strb[i]=strc[i]='0';
	scanf("%s", stra+10);//数组中预留下10位的进位,
	strcpy(strc, stra);
	strb[strlen(stra)] = '\0';
	int cnt = 0;
	int a = 10;
	int b = 10;
	int c = 10;
	while ((!judge(strc,c))&&cnt<10)
	{
		strcpy(stra, strc);
		i = 0;
		while (stra[i] == '0')i++;
		a = i;
		int temp = strlen(stra)-1;
		for (i=a; i < strlen(stra); i++)//将A翻转，拷贝给B
			strb[temp--] = stra[i];
		int flag = 0;//进位标志
		for (i = strlen(stra) - 1; i >= a; i--)//计算C
		{
			strc[i] = ((stra[i] - '0' + strb[i] - '0'+flag) % 10 ) + '0';
			if ((stra[i] - '0' + strb[i] - '0' + flag) >= 10)
			{
				flag = 1;
			}
			else
				flag = 0;
		}
		if (flag == 1)
			strc[i] = '1';
		i = 0;
		while (stra[i] == '0')i++;
		a = i;
		i = 0;
		while (strb[i] =='0')i++;
		b = i;
		i = 0;
		while (strc[i] == '0')i++;
		c = i;
		printf("%s + %s = %s\n", stra+a, strb+b, strc+c);//从第一个非0位开始输出
		cnt++;
	}
	if (cnt != 10)
		printf("%s is a palindromic number.", strc + c);
	else
		printf("Not found in 10 iterations.");
	return 0;
}