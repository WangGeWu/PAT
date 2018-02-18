#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct rnode
{
	int x, y;
}result[90000];
struct node
{
	int num;
	int fri[310];
	int sex;
}list[10010];
int cmp(const void *a, const void *b)
{
	if (((struct rnode*)a)->x != ((struct rnode*)b)->x)
		return ((struct rnode*)a)->x - ((struct rnode*)b)->x;
	else
		return ((struct rnode*)a)->y - ((struct rnode*)b)->y;
}
int find(int x, int n)
{
	for (int i = 0; i < list[x].num; i++)
		if (list[x].fri[i] == n)
			return 1;
	return 0;
}
int main()
{
	int n, m;
	int i, j;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++)
	{
		char v1[6], v2[6];
		scanf("%s%s", v1, v2);
		if (v1[0] != '-')
			list[abs(atoi(v1))].sex = 1;//1表示男性
		else
			list[abs(atoi(v1))].sex = -1;//-1表示女性
		if (v2[0] != '-')
			list[abs(atoi(v2))].sex = 1;
		else
			list[abs(atoi(v2))].sex = -1;
		list[abs(atoi(v1))].fri[list[abs(atoi(v1))].num++] = abs(atoi(v2));//记录朋友
		list[abs(atoi(v2))].fri[list[abs(atoi(v2))].num++] = abs(atoi(v1));
	}
	int k;
	scanf("%d", &k);
	for (int b = 0; b < k; b++)
	{
		int v1, v2;
		char v3[6], v4[6];
		scanf("%s%s", v3, v4);
		v1 = abs(atoi(v3));
		v2 = abs(atoi(v4));
		int cnt = 0;
		for (i = 0; i < list[v1].num; i++)
		{
			if (list[v1].fri[i] == v2)continue;//不能直接找到V2
			if (list[list[v1].fri[i]].sex == list[v1].sex)//寻找V1的同性朋友p
			{
				int p = list[v1].fri[i];
				for (j = 0; j < list[p].num; j++)//寻找V2的同性朋友
				{
					if (list[p].fri[j] == v1)continue;//不能直接找到V1
					if (list[list[p].fri[j]].sex == list[v2].sex&&find(list[p].fri[j], v2))
					{
						int q = list[p].fri[j];
						result[cnt].x = p; result[cnt].y = q;
						cnt++;
					}
				}
			}
		}
		printf("%d\n", cnt);
		qsort(result, cnt, sizeof(struct rnode), cmp);
		for (int a = 0; a < cnt; a++)
			printf("%04d %04d\n", result[a].x, result[a].y);
	}
	return 0;
}