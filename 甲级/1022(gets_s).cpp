#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max 10001
struct node 
{
	char ID[8];
	char title[81];
	char author[81];
	char key[100];
	char pubisher[81];
	char years[6];
}book[Max];
int cmp(const void* a, const void* b)
{
	struct node* p = (struct node*)a;
	struct node* q = (struct node*)b;
	return strcmp(p->ID, q->ID);
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
		gets_s(book[i].ID, 100);
		gets_s(book[i].title, 100);
		gets_s(book[i].author, 100);
		gets_s(book[i].key, 100);
		gets_s(book[i].pubisher, 100);
		gets_s(book[i].years, 100);
		i++;
	}
	qsort(book, n, sizeof(struct node), cmp);
	int sign;
	char str[101];
	scanf("%d", &m);
	while (m)
	{
		scanf("%d:", &sign);
		getchar();
		gets_s(str, 100);
		printf("%d:%s\n", sign, str);
		switch (sign)
		{
		case 1:Title(str, n); break;
		case 2:Author(str, n); break;
		case 3:Key(str, n); break;
		case 4:Pubisher(str, n); break;
		case 5:Years(str, n); break;
		}
		m--;
	}
	return 0;
}