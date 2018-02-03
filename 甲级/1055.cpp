#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	char name[9];
	int age;
	int money;
}man[100001];
int cmp(const void *a, const void *b)//按money>age>name的优先顺序排序
{
	if (((struct node*)a)->money != ((struct node*)b)->money)
		return ((struct node*)b)->money - ((struct node*)a)->money;
	else
	{
		if (((struct node*)a)->age != ((struct node*)b)->age)
			return ((struct node*)a)->age - ((struct node*)b)->age;
		else
			return strcmp(((struct node*)a)->name, ((struct node*)b)->name);
	}
}
int main()
{
	int n, m;
	//input
	scanf("%d%d", &n, &m);
	int i, j;
	for (i = 0; i < n; i++)
	{
		scanf("%s %d %d", &man[i].name, &man[i].age, &man[i].money);
	}
	//process
	qsort(man, n, sizeof(struct node), cmp);
	int cnt;
	for (i = 0; i < m; i++)
	{
		cnt = 0;
		int num, age1, age2;
		scanf("%d%d%d", &num, &age1, &age2);
		printf("Case #%d:\n",i+1);
		for (j = 0; j < n; j++)
		{
			if (man[j].age >= age1&&man[j].age <= age2&&cnt<num)
			{
				cnt++;
				printf("%s %d %d\n", man[j].name, man[j].age, man[j].money);
			}
		}
		if (cnt == 0)
			printf("None\n");
	}
}