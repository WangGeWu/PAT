#include<stdio.h>
#include<stdlib.h>
#define inf 999999999
int visited[501];
int graph_dist[501][501];
int graph_time[501][501];
int cost_dist[501];
int path_dist[501];
int path_time[501];
int cost_time[501];
int node_num[501];
int start, end;
int check()
{
	int i = end;
	while (path_dist[i] != -1&&path_time[i]!=-1)
	{
		if (path_dist[i] != path_time[i])
			return 0;
		i = path_dist[i];
	}
		return 1;
}
void Print_dist(int node)
{
	if (path_dist[node] != -1)
		Print_dist(path_dist[node]);
	if(path_dist[node]==-1)
		printf("%d", node);
	else
	printf(" -> %d", node);
}
void Print_time(int node)
{
	if (path_time[node] != -1)
		Print_time(path_time[node]);
	if (path_time[node] == -1)
		printf("%d", node);
	else
		printf(" -> %d", node);
}
int main()
{
	//input
	int n, m;
	int i, j;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
	{
		cost_time[i] = inf;
		cost_dist[i] = inf;
		path_dist[i] = -1;
		for (j = 0; j < n; j++)
		{
			graph_dist[i][j] = graph_time[i][j] = inf;
		}
	}
	for (i = 0; i < m; i++)
	{
		int v1, v2;
		int flag;
		int e, t;
		scanf("%d%d%d%d%d", &v1, &v2, &flag, &e, &t);
		if (flag)
		{
			graph_dist[v1][v2] = e;
			graph_time[v1][v2] = t;
		}
		else
		{
			graph_dist[v1][v2] = graph_dist[v2][v1] = e;
			graph_time[v1][v2] = graph_time[v2][v1] = t;
		}
	}
	scanf("%d%d", &start, &end);
	//process
	//dijstra_dist
	cost_dist[start] = 0;
	visited[start] = 1;
	cost_time[start] = 0;
	for (i = 0; i < n; i++)
	{
		if (visited[i] == 0 && graph_dist[start][i] < inf)
		{
			cost_dist[i] = graph_dist[start][i];
			path_dist[i] = start;
		}
	}
	int min;
	int flag_dij;
	int node;
	while (1)
	{
		min = inf;
		flag_dij = 0;
		//findmin
		for (i = 0; i < n; i++)
		{
			if (visited[i] == 0 && cost_dist[i] < min)
			{
					min = cost_dist[i];
					node = i;
					flag_dij = 1;
			}
		}
		if (!flag_dij)break;
		visited[node] = 1;
		for (i = 0; i < n; i++)
		{
			if (visited[i] == 0 && graph_dist[node][i] < inf)
			{
				if (cost_dist[i] > cost_dist[node] + graph_dist[node][i])
				{
					cost_dist[i] = cost_dist[node] + graph_dist[node][i];
					path_dist[i] = node;
				}
				else if (cost_dist[i] == cost_dist[node] + graph_dist[node][i])
				{
					if (cost_time[i] > cost_time[node] + graph_time[node][i])
					{
						cost_time[i] = cost_time[node] + graph_time[node][i];
						path_time[i] = node;
					}
				}
			}
		}
	}
	//dijstra_time
	for (i = 0; i < n; i++)
	{
		cost_time[i] = inf;
		visited[i] = 0;
		path_time[i] = -1;
	}
	cost_time[start] = 0;
	node_num[start] = 1;
	visited[start] = 1;
	for (i = 0; i < n; i++)
		if (visited[i] == 0 && graph_time[start][i] < inf)
		{
			cost_time[i] = graph_time[start][i];
			path_time[i] = start;
			node_num[i] = 2;
		}
	while (1)
	{
		min = inf;
		flag_dij = 0;
		//findmin
		for (i = 0; i < n; i++)
		{
			if (visited[i] == 0 && cost_time[i] < min)
			{
				min = cost_time[i];
				node = i;
				flag_dij = 1;
			}
		}
		if (!flag_dij)break;
		visited[node] = 1;
		for (i = 0; i < n; i++)
		{
			if (visited[i] == 0 && graph_time[node][i] < inf)
			{
				if (cost_time[i] > cost_time[node] + graph_time[node][i])
				{
					cost_time[i] = cost_time[node] + graph_time[node][i];
					node_num[i] = node_num[node] + 1;
					path_time[i] = node;
				}
				else if (cost_time[i] == cost_time[node] + graph_time[node][i])
				{
					if (node_num[i] > node_num[node] + 1)
					{
						node_num[i] = node_num[node] + 1;
						path_time[i] = node;
					}
				}
			}
		}
	}
	if (check())
	{
		printf("Distance = %d;", cost_dist[end]);
		printf(" Time = %d: ", cost_time[end]);
		Print_dist(end);
	}
	else
	{
		printf("Distance = %d: ", cost_dist[end]);
		Print_dist(end);
		printf("\n");
		printf("Time = %d: ", cost_time[end]);
		Print_time(end);
	}
	return 0;
}