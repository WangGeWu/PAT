#include<stdio.h>
#define Max 500
#define Inf 999999
int main()
{
	int G[Max][Max];
	int i, j;
	int v1, v2;
	int rescue[Max];//æ»‘Æ∂”
	int men[Max];
	int dist[Max];
	int num[Max];
	int visited[Max];
	int nv, ne, start, end,weight;
	scanf("%d %d %d %d", &nv, &ne, &start, &end);
	for (i = 0; i < nv; i++)
	{
		scanf("%d", &rescue[i]);
		visited[i] = 0;
		for (j = 0; j < nv; j++)
		{
			if (i == j)G[i][j] = 0;
			else
				G[i][j] = Inf;
		}
	}
	for (i = 0; i < ne; i++)
	{
		scanf("%d %d %d",&v1,&v2,&weight);
		G[v1][v2] = weight;
		G[v2][v1] = weight;
	}
	for (i = 0; i < nv; i++)
	{
		dist[i] = G[start][i];
	}
	for (i = 0; i < nv; i++)
	{
		if (G[start][i] < Inf&&start!=i)
		{
			men[i] = rescue[i] + rescue[start];
			num[i] = 1;
		}
		else if(G[start][i] == Inf)
			men[i] = -99; 
	}
	num[start] = 1;
	men[start] = rescue[start];
	visited[start] = 1;
	int temp, Min;
	while (1)
	{
		temp = -1; Min = Inf;
		for (i = 0; i < nv; i++)
		{
			if (Min > dist[i] && visited[i] == 0)
			{
				temp = i;
				Min = dist[i];
			}
		}
		if (temp == -1)break;
		visited[temp] = 1;
		for (i = 0; i < nv; i++)
		{
			if (G[temp][i] < Inf&&visited[i] == 0)
			{
				if (dist[i] > dist[temp] + G[temp][i])
				{
					dist[i] = dist[temp] + G[temp][i];
					num[i] = num[temp];
					men[i] = men[temp] + rescue[i];
				}
				else if (dist[i] == dist[temp] + G[temp][i])
				{
					num[i] = num[i] + num[temp];
					if (men[i] < men[temp] + rescue[i])
						men[i] = men[temp] + rescue[i];
				}
			}
		}
	}
	printf("%d %d\n", num[end], men[end]);
	return 0;
}