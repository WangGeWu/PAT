//2个点没过
#include<stdio.h>
#include<stdlib.h>
struct stunode
{
	int father=-1;
}stu[1000];
struct hobnofr
{
	int num=0;
	int student[100];
}hob[1000];
int cmp(const void*a, const void*b)
{
	return ((struct stunode*)a)->father - ((struct stunode*)b)->father;
}
int find(int v)
{
	while (stu[v].father >= 0)
	{
		v = stu[v].father;
	}
	return v;
}
void uion(int v1, int v2)
{
	int f1 = find(v1);
	int f2 = find(v2);
	if (f1 != f2)
	{
		stu[f1].father += stu[f2].father;
		stu[f2].father = f1;
	}
}
int main()
{
	int n;
	int i, j,k;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		int m;
		scanf("%d:", &m);
		for (j = 0; j < m; j++)
		{
			int h;
			scanf("%d", &h);
			hob[h].student[hob[h].num++] = i;
			if (hob[h].num > 1)
			{
				for (k = 1; k < hob[h].num; k++)
					uion(hob[h].student[0], hob[h].student[k]);
			}
		}
	}
	qsort(stu, n, sizeof(struct stunode), cmp);
	i = 0;
	while (stu[i].father < 0)
		i++;
	printf("%d\n%d", i,-stu[0].father);
	for (j = 1; j < i; j++)
	{
		printf(" %d", -stu[j].father);
	}
	return 0;
}