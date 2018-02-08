#include<stdio.h>
#include<stdlib.h>
struct node
{
	char name[11];
	char id[11];
	int grade;
}stu[10000];
int cmp(const void *a, const void *b)
{
	return ((struct node*)a)->grade < ((struct node*)b)->grade;
}
int main()
{
	int a, b;
	int n, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%s%s%d", &stu[i].name, &stu[i].id, &stu[i].grade);
	}
	scanf("%d%d", &a, &b);
	qsort(stu, n, sizeof(struct node), cmp);
	int flag = 0;
	for (i = 0; i < n; i++)
	{
		if (stu[i].grade >= a&&stu[i].grade <= b)
		{
			printf("%s %s\n", stu[i].name, stu[i].id);
			flag = 1;
		}
	}
	if (flag == 0)printf("NONE");
	return 0;
}