#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max 10001
struct node {
	char ID[8];
	char title[81];
	char author[81];
	char key[100];
	char pubisher[81];
	char years[6];
}book[Max];
int cmp(const void* a, const void* b)
{
	return strcmp(((struct node*)a)->ID, ((struct node*)b)->ID);
}
void Title(char s[], int n)
{
	int i = 0;
	int flag = 0;
	while (i<n)
	{
		if (strcmp(book[i].title, s) == 0)
		{
			flag = 1;
			printf("%s\n", book[i].ID);
		}
		i++;
	}
	if (flag == 0)printf("Not Found\n");
}
void Author(char s[], int n)
{
	int i = 0;
	int flag = 0;
	while (i<n)
	{
		if (strcmp(book[i].author, s) == 0)
		{
			printf("%s\n", book[i].ID);
			flag = 1;
		}
		i++;
	}
	if (flag == 0)
		printf("Not Found\n");
}
void Key(char s[], int n)
{
	int i = 0;
	int flag = 0;
	while (i<n)
	{
		if (strstr(book[i].key, s))
		{
			printf("%s\n", book[i].ID);
			flag = 1;
		}
		i++;
	}
	if (flag == 0)
		printf("Not Found\n");
}
void Pubisher(char s[], int n)
{
	int i = 0;
	int flag = 0;
	while (i<n)
	{
		if (strcmp(book[i].pubisher, s) == 0)
		{
			printf("%s\n", book[i].ID);
			flag = 1;
		}
		i++;
	}
	if (flag == 0)
		printf("Not Found\n");
}
void Years(char s[], int n)
{
	int i = 0;
	int flag = 0;
	while (i<n)
	{
		if (strcmp(book[i].years, s) == 0)
		{
			printf("%s\n", book[i].ID);
			flag = 1;
		}
		i++;
	}
	if (flag == 0)
		printf("Not Found\n");
}
int main()
{
	int i = 0;
	int n, m;
	scanf("%d", &n);
	getchar();
	while (i<n)
	{
		gets(book[i].ID);
		gets(book[i].title);
		gets(book[i].author);
		gets(book[i].key);
		gets(book[i].pubisher);
		gets(book[i].years);
		i++;
	}
	qsort(book, n, sizeof(struct node), cmp);
	scanf("%d", &m);
	while (m--)
	{
		char str[100];
		int sign;
		scanf("%d: ", &sign);
		gets(str);
		printf("%d: %s\n", sign, str);
		switch (sign)
		{
		case 1:Title(str, n); break;
		case 2:Author(str, n); break;
		case 3:Key(str, n); break;
		case 4:Pubisher(str, n); break;
		case 5:Years(str, n); break;
		}
	}
	return 0;
}
