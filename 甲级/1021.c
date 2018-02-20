#include<stdio.h>
#define inf 9999
int n;
int visit[10000];
int node[10000];
int graph[10000][10000];
int deep[10000];
void dfs_two(int v)
{
	int i;
	visit[v] = 1;
	for (i = 0; i < n; i++)
	{
		if (graph[v][i] < inf&&visit[i] == 0)
		{
			visit[i] = 1;
			deep[i] = deep[v] + 1;
			dfs_two(i);
		}
	}
}
void dfs(int v)
{
	int i;
	visit[v] = 1;
	for (i = 0; i < n; i++)
	{
		if (graph[v][i] < inf&&visit[i] == 0)
		{
			visit[i] = 1;
			dfs(i);
		}
	}
}
int FindMax()
{
	int i;
	int max = -1;
	for (i = 0; i < n; i++)
	{
		if (max < deep[i])
		{
			max = deep[i];
		}
	}
	return max;
}
void create()
{
	for (int i = 0; i < n; i++)
		deep[i] = 0;
}
int main()
{
	int i;
	//ÊäÈë
	scanf("%d", &n);
	for (i = 0; i < 10000; i++)
	{
		visit[i] = 0;
		for (int j = 0; j < 10000; j++)
			graph[i][j] = inf;
	}
	for (i = 0; i < n - 1; i++)
	{
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		v1--; v2--;
		graph[v1][v2] = graph[v2][v1] = 1;
	}
	//Í³¼ÆÁ¬Í¨·ÖÁ¿
	int cnt = 0;
	int Max = -1;
	for (i = 0; i < n; i++)
	{
		if (visit[i] == 0)
		{
			dfs(i);
			cnt++;
		}
	}
	if (cnt == 1)
	{
		for (i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				visit[j] = 0;
			deep[i] = 0;
			dfs_two(i);
			node[i] = FindMax();
			if (node[i] > Max)
				Max = node[i];
		}
		for (i = 0; i < n; i++)
			if (node[i] == Max)
				printf("%d\n", i + 1);
	}
	else
	{
		printf("Error: %d components", cnt);
	}
	return 0;
}
