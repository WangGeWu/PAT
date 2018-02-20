#include<stdio.h>
#include<stdlib.h>
#define inf 9999999
int numTostr[20000];
int strTonum[200];
int visited[200];
int path[200];
int dist[200];//花费
int num[200];//最短路径数
int happiness[200];//每个城市的幸福值
int trahappiness[200];//经过的节点幸福总值
int nodenum[200];//节点最短路径经过的节点数
void Print(int n)
{
	int x = strTonum[n];
	char city[4];
	city[0] = 'A' + x / 26 / 26;
	x = x % (26 * 26);
	city[1] = 'A' + x / 26;
	x = x % 26;
	city[2] = 'A' + x;
	city[3] = '\0';
	if (path[n] != -1)
		Print(path[n]);
	if (path[n] == -1)
		printf("%s", city);
	else
		printf("->%s", city);
}
int main()
{
	int i, j;
	int n, k;
	int graph[200][200];
	scanf("%d%d", &n, &k);
	for (i = 0; i < n; i++)
	{
		dist[i] = inf;
		path[i] = -1;
		for (j = 0; j < n; j++)
			graph[i][j] = inf;
	}
	char city[4];
	scanf("%s", city);
	int m = (city[0] - 'A') * 26 * 26 + (city[1] - 'A') * 26 + (city[2] - 'A');//将字符串转换为26进制的数
	numTostr[m] = 0;
	strTonum[0] = m;
	for (i = 1; i < n; i++)
	{
		scanf("%s", city);
		int m = (city[0] - 'A') * 26 * 26 + (city[1] - 'A') * 26 + (city[2] - 'A');
		numTostr[m] = i;
		strTonum[i] = m;
		scanf("%d", &happiness[i]);
	}
	char s1[5], s2[5];
	for (i = 0; i < k; i++)
	{
		scanf("%s%s", s1, s2);
		int w;
		scanf("%d", &w);
		int v1 = (s1[0] - 'A') * 26 * 26 + (s1[1] - 'A') * 26 + (s1[2] - 'A');
		int v2 = (s2[0] - 'A') * 26 * 26 + (s2[1] - 'A') * 26 + (s2[2] - 'A');
		graph[numTostr[v1]][numTostr[v2]] = graph[numTostr[v2]][numTostr[v1]] = w;
	}
	//dijkstr
	visited[0] = 1;
	dist[0] = 0;
	path[0] = -1;
	nodenum[0] = 0;
	for (i = 0; i < n; i++)
	{
		if (graph[0][i] < inf&&i != j)
		{
			num[i] = 1;
			nodenum[i] = 1;
			dist[i] = graph[0][i];
			path[i] = 0;
			trahappiness[i] = happiness[i];
		}
	}
	int min, flag, node;
	while (1)
	{
		min = inf; flag = 0;
		//Findmin
		for (i = 0; i < n; i++)
		{
			if (visited[i] == 0 && dist[i] < min)
			{
				min = dist[i];
				flag = 1;
				node = i;
			}
		}
		if (flag == 0)break;
		visited[node] = 1;
		for (i = 0; i < n; i++)
		{
			if (visited[i] == 0 && graph[node][i]<inf)
			{
				if (dist[i] > dist[node] + graph[node][i])
				{
					dist[i] = dist[node] + graph[node][i];//花费
					path[i] = node;//路径
					trahappiness[i] = trahappiness[node] + happiness[i];//幸福总值
					num[i] = num[node];
					nodenum[i] = nodenum[node] + 1;//路过节点数
				}
				else if (dist[i] == dist[node] + graph[node][i])
				{
					num[i] = num[node] + num[i];//路径数
					if (trahappiness[i] < trahappiness[node] + happiness[i])
					{
						trahappiness[i] = trahappiness[node] + happiness[i];//幸福总值
						path[i] = node;//路径
						nodenum[i] = nodenum[node] + 1;//路过节点数
					}
					else if (trahappiness[i] == trahappiness[node] + happiness[i])
					{
						if (trahappiness[i] / nodenum[i] < (trahappiness[node] + happiness[i]) / (nodenum[node] + 1))
						{
							path[i] = node;//路径
							nodenum[i] = nodenum[node] + 1;//路过节点数
						}
					}
				}
			}
		}
	}
	int res = ('R' - 'A') * 26 * 26 + ('O' - 'A') * 26 + 'M' - 'A';
	int x = numTostr[res];
	printf("%d %d %d %d\n", num[x], dist[x], trahappiness[x], trahappiness[x] / nodenum[x]);
	Print(x);
	return 0;
}
