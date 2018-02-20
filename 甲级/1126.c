#include<stdio.h>
int graph[501][501];
int visited[501] = {0};
int n;
void dfs(int v)
{
	visited[v] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (visited[i] == 0 && graph[v][i] == 1)
			dfs(i);
	}
}
int main()
{
	int degree[501]={0};
	int m;
	int i, j;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++)
	{
		int v1, v2;
		scanf("%d%d", &v1, &v2);
		degree[v1]++;
		degree[v2]++;
		graph[v1][v2] = graph[v2][v1] = 1;
	}
	int cnt = 0;
	for (i = 1; i <= n; i++)
	{
		if (visited[i] == 0)
		{
			dfs(i);
			cnt++;
		}
	}
	for (i = 1; i <= n; i++)
	{
		if (i != 1)
			printf(" ");
		printf("%d", degree[i]);
	}
	if (cnt > 1)
		printf("\nNon-Eulerian");
	else
	{
		int even_cnt = 0, odd_cnt = 0;
		for (i = 1; i <= n; i++)
		{
			if (degree[i] % 2 != 0)
				odd_cnt++;
		}
		if (odd_cnt == 2)
			printf("\nSemi-Eulerian");
		else if (odd_cnt == 0)
			printf("\nEulerian");
		else
			printf("\nNon-Eulerian");
	}
	return 0;
}
