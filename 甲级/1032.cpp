#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	char word;
	int next;
	int visited;
}list;
int main()
{
	list* a = (list*)malloc(sizeof(struct node) * 100000);
	int ad1, ad2, n;
	int i,j;
	//input
	scanf("%d %d %d", &ad1, &ad2, &n);
	if (ad1 == -1 || ad2 == -1)
	{
		printf("-1");
		return 0;
	}
	int address;
	for (i = 0; i < n; i++)
	{
		scanf("%d",&address);
		scanf(" %c %d", &a[address].word, &a[address].next);
		a[address].visited = 0;
	}
	//process
	//traval
	i = ad1;
	while (a[i].next!=-1)
	{
		a[i].visited = 1;
		i = a[i].next;
	}
	a[i].visited = 1;
	i = ad2;
	while (a[i].next != -1)
	{
		if (a[i].visited == 1)
		{
			printf("%05d", i);
			return 0;
		}
		else
			i = a[i].next;
	}
	if (a[i].next == -1)
	{
		if (a[i].visited == 1)
			printf("%05d", i);
		else
			printf("-1");
	}
	//output
	free(a);
	return 0;
}