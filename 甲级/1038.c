#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char str[10001][9];
//cmp函数的应用
//若字符串a、b拼接的值大于b、a拼接的值，则a应该排在b的后面
int cmp(const void *a, const void *b)
{
	char str1[18], str2[18];
	strcpy(str1, (char*)a);
	strcpy(str2, (char*)b);
	strcat(str1, str2);
	strcat(str2, (char*)a);
	return strcmp(str1, str2);
}
int main()
{
	int n;
	int i,j;
	scanf("%d",&n);
	getchar();
	for (i = 0; i < n; i++)
	{
		scanf("%s",str[i]);
	}
	qsort(str[0], n, 9 * sizeof(char), cmp);
	int flag = 0;
	for (i = 0; i < n; i++)
	{
		for(j=0;str[i][j]!='\0';j++)
		{
			if (flag==1||str[i][j]!='0')
			{
				printf("%c", str[i][j]);
				flag = 1;
			}	
		}
	}
	if (flag == 0)
		printf("0");
	return 0;
}
