#include<stdio.h>
#include<stdlib.h>
#define inf 999999999
int n;
int visit[10010];
int result[20000];
struct node
{
	int child_num;
	int child[10000];
}list[10010];
int deep[10010];
int flag[10010];
int cmp(const void *a, const void *b)
{
	return *(int*)a > *(int*)b;
}
void dfs(int v)
{
	int i;
	visit[v] = 1;
	for (i = 0; i < list[v].child_num; i++)
	{
		if (visit[list[v].child[i]] == 0)
		{
			deep[list[v].child[i]] = deep[v] + 1;
			dfs(list[v].child[i]);
		}
	}
}
int main()
{
	int i;
	//输入
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		visit[i] = 0;
		flag[i] = 0;
	}
	for (i = 0; i < n - 1; i++)
	{
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		list[v1].child[list[v1].child_num++] = v2;
		list[v2].child[list[v2].child_num++] = v1;
	}
	//统计连通分量
	int cnt = 0;
	deep[1] = 0;
	for (i = 1; i <= n; i++)
	{
		if (visit[i] == 0)
		{
			dfs(i);
			cnt++;
		}
	}
	if (cnt<2)
	{
		int Max = -1;
		cnt = 0;
		for (i = 1; i <= n; i++)
		{
			if (deep[i] > Max)
			{
				cnt = 0;
				result[cnt++] = i;
				Max = deep[i];
			}
			else if (deep[i] == Max)
				result[cnt++] = i;
		}
		int temp = cnt;
		for (i = 1; i <= n; i++)
			visit[i] = 0;
		deep[result[0]] = 0;
		dfs(result[0]);
		Max = -1;
		for (i = 1; i <= n; i++)
		{
			if (deep[i] > Max)
			{
				cnt = temp;
				result[cnt++] = i;
				Max = deep[i];
			}
			else if (deep[i] == Max)
				result[cnt++] = i;
		}
		qsort(result, cnt, sizeof(int), cmp);
		for (i = 0; i < cnt; i++)
		{
			if (flag[result[i]] == 0)
			{
				flag[result[i]] = 1;
				printf("%d\n", result[i]);
			}
		}
	}
	else
	{
		printf("Error: %d components", cnt);
	}
	return 0;
}
