#include<stdio.h>
#include<stdlib.h>
#define inf 999
int visited[501];
int dist[501];
int part[501];
int costed[501];
int graph[501][501];
int cost[501][501];
void Print(int s)
{
	if (part[s] != -1)
	{
		Print(part[s]);
	}
	printf("%d ",s);
}
int main()
{
	int i,j;
	int n, m, s, d;
	for (i = 0; i < 501; i++)//初始化
	{
		part[i] = -1;
		dist[i] = inf;
		visited[i] = 0;
		costed[i] = inf;
		for (j = 0; j < 501; j++)
		{
			cost[i][j] = inf;
			graph[i][j] = inf;
		}
	}
	//input
	scanf("%d %d %d %d", &n, &m, &s, &d);
	for (i = 0; i < m; i++)
	{
		int v1, v2,e,c;
		scanf("%d %d %d %d", &v1, &v2,&e,&c);
		graph[v1][v2] = graph[v2][v1] = e;
		cost[v1][v2] = cost[v2][v1] = c;
	}
	//process
	//Dijkstra
	for (i = 0; i < n; i++)
	{
		dist[i] = graph[s][i];
		if (dist[i] < inf)
		{
			costed[i] = cost[s][i];
			part[i] = s;
		}
	}
	visited[s] = 1;
	dist[s] = 0;
	int min;
	int node;
	int flag;
	while (1)
	{
		flag = 0;
		min = inf;
		//FindMin
		for (i = 0; i < n; i++)
		{
			if (dist[i] < min&&visited[i] == 0)
			{
				flag = 1;
				min = dist[i];
				node = i;
			}
		}
		if (flag == 0)break;
		visited[node] = 1;
		for (i = 0; i < n; i++)
		{
			if (graph[node][i] < inf&&visited[i] == 0)
			{
				if (dist[i] > dist[node] + graph[node][i])
				{
					dist[i] = dist[node] + graph[node][i];
					part[i] = node;
					costed[i] = costed[node] + cost[node][i];
				}
		     	else if(dist[i] == dist[node] + graph[node][i])
				{
					if (costed[i] > costed[node] + cost[node][i])
					{
						part[i] = node;
						costed[i] = costed[node] + cost[node][i];
					}
				}
			}
	    }
	}
	//output
	Print(d);
	printf("%d %d", dist[d], costed[d]);
	return 0;
}
