//图的连通分量等于需要深度遍历的次数
//将N个连通分量连接起来需要N-1条边
#include<stdio.h>
int Graph[1001][1001];
int visited[1001];
void dfs(int v)
{
	int i;
	visited[v] = 1;
	for(i=0;i<1001;i++)
		if (Graph[v][i] == 1 && visited[i] == 0)
		{
			visited[i] = 1;
			dfs(i);
		}
}
int main()
{
	int i,j;
	int cnt;
	int v, e, n;
	int k;
	int city1, city2;
    for(i=0;i<1001;i++)
		for (j = 0; j < 1001; j++)
			Graph[i][j] = 0;
	scanf("%d %d %d", &v, &e, &n);
	for (i = 0; i < e; i++)
	{
		scanf("%d %d", &city1, &city2);
		Graph[city1-1][city2-1] = Graph[city2-1][city1-1] = 1;
	}
	for (i = 0; i < n; i++)
	{
		cnt = 0;
		for(j=0;j<1001;j++)
		    visited[j] = 0;
		scanf("%d", &k);
		visited[k-1] = 1;
		for (j = 0; j < v; j++)
		{
			if (visited[j] == 0)
			{
				dfs(j);
				cnt++;
			}
		}
		printf("%d\n", cnt-1);
	}
	return 0;
}
