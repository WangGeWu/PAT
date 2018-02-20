//Ò»¸ö²âÊÔµãÃ»AC
#include<stdio.h>
#include<stdlib.h>
#define inf 9999999
int graph[1011][1011];
int visit[1011];
struct node
{
	int id;
	float mindis;
	float ave;
}G[11];
int dist[1011][1011];
int n, m, k, ds;
int cmp(const void *a, const void*b)
{
	if (((struct node*)a)->mindis != ((struct node*)b)->mindis)
		return ((struct node*)b)->mindis > ((struct node*)a)->mindis;
	else
	{
		if (((struct node*)a)->ave != ((struct node*)b)->ave)
			return ((struct node*)a)->ave > ((struct node*)b)->ave;
		else
			return ((struct node*)a)->id > ((struct node*)b)->id;
	}
}
void dijkstr(int v)
{
	int i;
	for (i = 0; i < m + n; i++)
	{
		visit[i] = 0;
		dist[v][i] = inf;
	}
	visit[v] = 1;
	dist[v][v] = 0;
	for (i = 0; i < n+m; i++)
	{
		if (graph[v][i] < inf&&visit[i] == 0)
		{
			dist[v][i] = graph[v][i];
		}
	}
	int node;
	int min;
	int flag;
	while (1)
	{
		flag = 0;
		min = inf;
		for (i = 0; i < m + n; i++)
		{
			if (visit[i] == 0 && min > dist[v][i])
			{
				flag = 1;
				min = dist[v][i];
				node = i;
			}
		}
		if (flag == 0)break;
		visit[node] = 1;
		for (i = 0; i < m + n; i++)
		{
			if (visit[i] == 0)
			{
				if (dist[v][i] > dist[v][node] + graph[node][i])
					dist[v][i] = dist[v][node] + graph[node][i];
			}
		}
	}
}
int main()
{
	scanf("%d%d%d%d", &n, &m, &k, &ds);
	int i,j;
	for(i=0;i<n+m;i++)
		for (j = 0; j < n + m; j++)
		{
			graph[i][j] = inf;
		}
	for (i = 0; i < k; i++)
	{
		char s1[5]; char s2[5];
		int w, v1, v2;
		scanf("%s%s%d", s1, s2, &w);
		if (s1[0] != 'G')
		{
			v1 = atoi(s1) - 1;
		}
		else 
		{
			v1 = atoi(s1 + 1) + n - 1;
		}
		if (s2[0] != 'G')
			v2 = atoi(s2) - 1;
		else
		{
			v2 = atoi(s2 + 1) + n - 1;
		}
		graph[v1][v2] = graph[v2][v1] = w;
	}
	for (i = n; i < n + m; i++)
	{
		dijkstr(i);
	}
	float minx, num;
	for (i = n; i < n + m; i++)
	{
		G[i - n].id = i;
	    minx = 999999;
	    num = 0;
		for (j = 0; j < n; j++)
		{
			if (dist[i][j] > ds)
			{
				minx = -1;
				break;
			}
			num +=1.0*dist[i][j];
		    if (dist[i][j] < minx&&i!=j)
			{
				minx = dist[i][j];
			}
		}
		G[i - n].mindis = minx;
		if (minx == -1)continue;
		num = num / n;
		G[i - n].ave = num + 0.05;
	}
	qsort(G, m, sizeof(struct node), cmp);
	if (G[0].mindis == -1)
		printf("No Solution");
	else
	{
		printf("G%d\n",G[0].id - n + 1);
		printf("%.1f %.1f", G[0].mindis, G[0].ave);
	}
	return 0;
}
