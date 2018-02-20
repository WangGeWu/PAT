#include<stdio.h>
#include<string.h>
int main()
{
	char week[7][4]={ "MON","TUE","WED","THU","FRI","SAT","SUN" };
	int hour[256];
	for (char i = '0'; i <= '9'; i++)
		hour[i] = i - '0';
	for (char i = 'A'; i <= 'N'; i++)
		hour[i] = i - 'A' + 10;
	int i, j;
	char s1[61], s2[61], s3[61], s4[61];
	char key[2];
	scanf("%s%s%s%s", s1, s2, s3, s4);
	for (i = 0; i < 61; i++)
	{
		if (s1[i] == s2[i] && s1[i] >= 'A'&&s1[i] <= 'G')
		{
			key[0] = s1[i];
			break;
		}
	}
	for (i = i + 1; i < 61; i++)
	{
		if (s1[i] == s2[i] && ((s1[i] >= '0'&&s1[i] <= '9') ||(s1[i] >= 'A'&&s1[i] <= 'N')))
		{
			key[1] = s1[i];
			break;
		}
	}
	int min;
	for (i = 0; i < 61; i++)
	{
		if (s3[i] == s4[i] && ((s3[i] >= 'a'&&s3[i] <= 'z') || (s3[i] >= 'A'&&s3[i] <= 'Z')))
		{
			min = i;
			break;
		}
	}
	printf("%s %02d:%02d", week[key[0] - 'A'], hour[key[1]], min);
	return 0;
}
