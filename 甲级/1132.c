#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char s[20];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		long num;
		scanf("%ld", &num);
		sprintf(s, "%ld", num);
		long right = atoi(s + strlen(s) / 2);
		s[strlen(s) / 2] = '\0';
		long left = atoi(s);
		if (left&&right)
		{
			if (num % (left*right) == 0)//不能对0取余
				printf("Yes\n");
			else
				printf("No\n");
		}
		else
			printf("No\n");
	}
	return 0;
}
