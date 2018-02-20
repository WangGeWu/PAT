//先用Dijkstra求出最短路径，再利用DFS对等长的路径进行回溯，求最小的输出和返回
#include<stdio.h>
#define inf 999999999
struct path {
	int size;
	int vp[502];
}path[502];
int anspath[502], x = 0;//储存最终结果路径
int weight[502];
int visited[502];
int dist[502];
int stack[502];
int top = 0;
int send = inf;
int back = inf;
int Cmax, N, Sp, M;//站点可容纳的最多数量，站点数，站点下标，边的数量
void DFS(int v)
{
	int i;
	stack[top++] = v;
	if (v == 0)
	{
		int count = 0; int s = 0;
		for (i = top - 2; i >= 0; i--)
		{
			count += weight[stack[i]] - Cmax / 2;
			if (count < 0)
			{
				s += -count;
				count = 0;
			}
		}
		if (s<send || (s == send&&count<back))
		{
			send = s;
			back = count;
			x = 0;
			for (i = top - 1; i >= 0; --i)
				anspath[x++] = stack[i];
		}
		return;
	}
	for (i = 0; i < path[v].size; i++)
	{
		DFS(path[v].vp[i]);
		top--;
	}
}
int main()
{
	int graph[502][502];
	int i, j;
	for (i = 0; i < 502; i++)
	{
		dist[i] = inf;
		visited[i] = 0;
		for (j = 0; j < 502; j++)
		{
			path[i].vp[j] = -1;
			graph[i][j] = inf;
		}
	}
	scanf("%d %d %d %d", &Cmax, &N, &Sp, &M);
	for (i = 1; i <= N; i++)
	{
		scanf("%d", &weight[i]);
	}
	for (i = 0; i < M; i++)
	{
		int v1, v2, edge;
		scanf("%d %d %d", &v1, &v2, &edge);
		graph[v1][v2] = graph[v1][v2] = edge;
	}
	//Dijkstra
	for (i = 0; i <= N; i++)
	{
		if (graph[0][i] < inf)
		{
			dist[i] = graph[0][i];
			path[i].vp[path[i].size++] = 0;
		}
	}
	dist[0] = 0;
	visited[0] = 1;
	int node;
	int flag;
	int min;
	while (1)
	{
		flag = 0;	min = inf;
		for (i = 0; i <= N; i++)
		{
			if (min > dist[i] && visited[i] == 0)
			{
				flag = 1;
				node = i;
				min = dist[i];
			}
		}
		if (flag == 0)break;
		visited[node] = 1;
		for (i = 0; i <= N; i++)
		{
			if (visited[i] == 0 && graph[node][i] < inf)
			{
				if (dist[i] > dist[node] + graph[node][i])
				{
					dist[i] = dist[node] + graph[node][i];
					path[i].vp[0] = node;
					path[i].size = 1;
				}
				else if (dist[i] == dist[node] + graph[node][i])
				{
					path[i].vp[path[i].size++] = node;
				}
			}
		}

	}
	DFS(Sp);
	printf("%d ", send);
	for (int i = 0; i<x - 1; ++i)
		printf("%d->", anspath[i]);
	printf("%d %d", Sp, back);
	return 0;
}
