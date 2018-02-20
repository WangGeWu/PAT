#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 100000
struct node
{
	int id;
	char name[9];
	int grade;
}list[max];
int idcmp(const void *a,const void *b)
{
	return ((struct node*)a)->id - ((struct node*)b)->id;
}
int namecmp(const void *a, const void *b)
{
	if (strcmp(((struct node*)a)->name, ((struct node*)b)->name))
		return strcmp(((struct node*)a)->name, ((struct node*)b)->name);
	else
	{
		return ((struct node*)a)->id - ((struct node*)b)->id;
	}
}
int gradecmp(const void *a, const void *b)
{
	if (((struct node*)a)->grade - ((struct node*)b)->grade)
		return ((struct node*)a)->grade - ((struct node*)b)->grade;
	else
	{
		return ((struct node*)a)->id - ((struct node*)b)->id;
	}
}
int main()
{
	    int n,c;
		//input
		scanf("%d %d",&n,&c);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &list[i].id);
			scanf("%s", list[i].name);
			scanf("%d", &list[i].grade);
		}
		//precess
		switch (c)
		{
		case 1:qsort(list,n,sizeof(struct node),idcmp);break;
		case 2:qsort(list,n,sizeof(struct node),namecmp);break;
		case 3:qsort(list,n,sizeof(struct node),gradecmp);break;
		}
		//output
		for (int i = 0; i < n; i++)
		{
			printf("%06d %s %d\n", list[i].id, list[i].name, list[i].grade);
		}
		return 0;
}
