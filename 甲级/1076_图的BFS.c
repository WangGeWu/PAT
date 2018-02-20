#include<stdio.h>
#include<stdlib.h>
#define inf 9999999
int graph[1000][1000];
int visited[1000];
int n,d;
int deep[1000];
int bfs(int v)
{
	int i;
	for (i = 0; i < n; i++)
	{
		visited[i] = 0;
	}
	int cnt = 0;
	int queue[1000];
	int front=-1, rear=-1;
	visited[v] = 1;
	deep[v] = 1;
	queue[++rear] = v;//v入队
	while (front != rear)//队不空时
	{
		int node = queue[++front];//出队
		if (deep[node] > d + 1)//超过限制的人数
			break;
		else   
			cnt++;
		for (int i = 0; i < n; i++)
		{
			if (graph[node][i]==1&&visited[i] == 0)
			{
				visited[i] = 1;
				deep[i] = deep[node] + 1;//计算深度
				queue[++rear] = i;//入队
			}
		}
	}
	return cnt-1;
}
int main()
{
	int i, j;
	scanf("%d%d", &n,&d);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			graph[i][j] = inf;
	for (i = 0; i < n; i++)
	{
		int m;
		int v;
		scanf("%d", &m);
		for (j = 0; j < m; j++)
		{
			scanf("%d", &v);
			v--;
			graph[v][i] = 1;
		}
	}
	int k;
	scanf("%d", &k);
	for (i = 0; i < k; i++)
	{
		int x;
		scanf("%d", &x);
		printf("%d\n", bfs(x-1));
	}
	return 0;
}
