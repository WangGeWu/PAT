#include<stdio.h>
#include<string.h>
char s1[1001];
char s2[1001];
char s3[1001];
void EXC(char a[])//×ª»»
{
	int i=0, j;
	char temp;
	int len = strlen(a);
	j = len-1;
	while (i<j)
	{
		temp = a[i];
	    a[i] = a[j];
		a[j] = temp;
		i++; j--;
	}
}
int judge(char a[])//ÅÐ¶Ï
{
	int i=0, j=strlen(a)-1;
	while (i<j)
	{
		if (a[i] != a[j])
			return 0;
		i++; j--;
	}
	return 1;
}
void add(char a[], char b[])
{
	int flag = 0;
	int i;
	for (i = strlen(a) - 1; i >= 0; i--)
	{
		int num = a[i] - '0' + b[i] - '0'+flag;
		if (num >= 10)
		{
			flag = 1;
		}
		else
			flag = 0;
		s3[i] = num % 10 + '0';
	}
	if (flag == 1)
	{
		for (i = strlen(s3); i>0; i--)
			s3[i] = s3[i - 1];
		s3[0] = '1';
	}
	s3[strlen(s3)] = '\0';
}
int main()
{
	int n;
	int i = 0;
	int cnt = 0;
	//input
	scanf("%s", s1);
	scanf("%d", &n);
	//precess
	while (cnt<n)
	{
		if (!judge(s1))
		{
			strcpy(s2, s1);
			EXC(s2);
			add(s1,s2);
			strcpy(s1, s3);
		}
		else
		{
			printf("%s\n%d",s1,cnt);
			return 0;
		}
		cnt++;
	}
	printf("%s\n%d", s1, n);
	//output
	return 0;
}