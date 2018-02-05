#include<stdio.h>
#include<stdlib.h>
struct node
{
	float price;
	float v;
	float s;
}list[1001];
int cmp(const void *a, const void *b)
{
	return ((struct node*)a)->price < ((struct node*)b)->price;
}
int main()
{
	int n, m;
	int i;
	float x, y;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
	{
		scanf("%f", &x);
		list[i].s=x;
	}
	for (i = 0; i < n; i++)
	{
		scanf("%f", &y);
		list[i].v = y;
		list[i].price = list[i].v/list[i].s;
	}
	qsort(list, n, sizeof(struct node), cmp);
	float cnt_v = 0.0;
	i = 0;
	while (m&&i<n)
	{
		if (list[i].s <= m)
		{
			cnt_v += list[i].v;
				m=m-list[i].s;
		}
		else
		{
			cnt_v += m*list[i].price;
			m = 0;
		}
		i++;
	}
	printf("%.2f", cnt_v);
}