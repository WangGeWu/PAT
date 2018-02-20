#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int a, b,temp,cnt,length;
	char num[10] = { 0 };
	cnt = 0;
	scanf("%d %d", &a, &b);
	if (a < -1000000|| b>1000000)
	{
		printf("´íÎó");
		return 0;
	}
	temp = a + b;
	if (temp < 0)
		printf("-");
	temp = abs(temp);
	if (temp < 1000)
		printf("%d", temp);
	else
	{
		sprintf(num, "%d", temp);
		length = strlen(num);
		a=length % 3;
		b = 0;
		if (a != 0)
		{
			for (; b < a; b++)
				printf("%c", num[b]);
			printf(",");
		}
		while (num[b] != '\0')
		{
			printf("%c", num[b]);
			b++;
			cnt++;
			if (cnt == 3&&num[b]!='\0')
			{
				printf(",");
				cnt = 0;
			}
		}
	}
}
