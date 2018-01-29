#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
	char id[14];
	int flag;
	int test;
	int allrank;
	int partrank;
}list[30000];
int cmp(const void *a, const void *b)
{
	if (((struct node *)a)->test > ((struct node *)b)->test)
		return -1;
	else if (((struct node *)a)->test < ((struct node *)b)->test)
		return 1;
	else
	{
		return (strcmp(((struct node *)a)->id, ((struct node *)b)->id));
	}
}
int main()
{
	int num[101];
	int n, k;
	int cnt = 0;
	int x = 0;
	scanf("%d", &n);
	int temp = n;
	int i = 0, j = 0;
	//input
	while (n > 0)
	{
		scanf("%d", &k);
		int cnt1 = 0;
		while (cnt1 < k)
		{
			scanf("%s", list[j].id);
			scanf("%d", &list[j].test);
			list[j].flag = i + 1;
			j++;
			cnt1++;
		}
		num[i] = k;
		n--; i++;
	}
	//process
	//组内排序
	n = temp;
	for (i = 0; i < n; i++)
	{
		qsort(list + cnt, num[i], sizeof(struct node), cmp);
		for (j = 0; j < num[i]; j++)
		{
			if (j == 0)
			{
				list[x].partrank = 1;
			}
			else
			{
				if (list[x].test == list[x - 1].test)

				{
					list[x].partrank = list[x - 1].partrank;
				}
				else
				{
					list[x].partrank = j + 1;
				}
			}
			x++;
		}
		cnt = num[i]+cnt;
	}
	//全体排序
	cnt = 0;
	for (i = 0; i < n; i++)
	{
		cnt += num[i];
	}
	qsort(list, cnt, sizeof(struct node), cmp);
	for (i = 0; i < cnt; i++)
	{
		if (i == 0)
			list[i].allrank = 1;
		else
		{
			if (list[i].test == list[i - 1].test)
			{
				list[i].allrank = list[i - 1].allrank;
			}
			else
			{
				list[i].allrank = i + 1;
			}
		}
	}
	//output
	printf("%d\n", cnt);
	for (i = 0; i < cnt; i++)
	{
		printf("%s %d %d %d\n", list[i].id, list[i].allrank, list[i].flag, list[i].partrank);
	}
	return 0;
}