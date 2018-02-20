#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char numTostr1[13][5] = { "tret","jan","feb","mar","apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
char numTostr2[12][5] = { "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer","jou" };
int main()
{
	int i, j;
	int n;
	char s[15];
	scanf("%d", &n);
	getchar();
	for (j = 0; j < n; j++)
	{
		gets_s(s,14);
		if (s[0] >= '0'&&s[0] <= '9')
		{
			int num = atoi(s);
			if (num == 0)
				printf("%s\n", numTostr1[0]);
			else
			{
				if (num % 13 != 0)
				{
					if (num >= 13)
						printf("%s ", numTostr2[num / 13 - 1]);
					printf("%s\n", numTostr1[num % 13]);
				}
				else
					printf("%s\n", numTostr2[num / 13 - 1]);
			}
		}
		else
		{
			if (strlen(s) > 4)
			{
				int x, y;
				s[3] = '\0';
				for (i = 0; i < 12; i++)
					if (!strcmp(numTostr2[i], s))
						x = (i + 1) * 13;
				for (i = 0; i < 13; i++)
					if (!strcmp(numTostr1[i], s + 4))
						y = i;
				printf("%d\n", x + y);
			}
			else
			{
				for (i = 0; i < 13; i++)
					if (!strcmp(numTostr1[i], s))
						printf("%d\n", i);
				for (i = 0; i < 12; i++)
					if (!strcmp(numTostr2[i], s))
						printf("%d\n", (i + 1) * 13);
			}
		}
	}
	return 0;
}
