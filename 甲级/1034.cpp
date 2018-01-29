#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define indix 26
#define inf 9999999
int result[2001];
int resultmem[2001];
int graph[2001][2001];
int weight[2001];
int visited[2001];
int vnumTostr[2001];
int peoplenum;
int n, k;
int membernum=0;
int max = 0;
int node;
int edgenum = 0;
int vflag[17575];
void dfs(int v)//°´±ß±éÀú
{
	int i;
	if (visited[v] == 0)
		membernum++;
	visited[v] = 1;
	for (i = 0; i < peoplenum; i++)
	{
		if (graph[v][i] < inf&&graph[v][i]>0)
		{
			weight[i] += graph[v][i];
			if (max < weight[i])
			{
				max = weight[i];
				node = i;
			}
			weight[v] += graph[v][i];
			if (max < weight[v])
			{
				max = weight[v];
				node = v;
			}
			edgenum += graph[v][i];
			graph[v][i] = graph[i][v] = 0;
			dfs(i);
		}
	}
}
int main()
{
	char name[4];
	int i,j;
	for (i = 0; i < 17575; i++)
	{
		vflag[i] = -1;
	}
	for (i = 0; i < 2001; i++)
	{
		visited[i] = 0;
		weight[i] = 0;
		for (j = 0; j < 2001; j++)
			graph[i][j]=inf;
	}
	//input
	int cnt = 0;
	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++)
	{
		int v1, v2,e;
		int x, y;
		scanf("%s",name);
		v1 = (name[0] - 'A') * indix*indix + (name[1] - 'A') * indix + (name[2] - 'A');
		if (vflag[v1] == -1)
		{
			x = cnt++;
			vflag[v1] = x;
			vnumTostr[x] = v1;
		}
		getchar();
		scanf("%s", name);
		v2 = (name[0] - 'A') * indix*indix + (name[1] - 'A') * indix + (name[2] - 'A');
		if (vflag[v2] == -1)
		{
			y = cnt++;
			vflag[v2] = y;
			vnumTostr[y] = v2;
		}
		scanf("%d", &e);
		if (graph[vflag[v1]][vflag[v2]] < inf)
		{
			graph[vflag[v1]][vflag[v2]] += e;
			graph[vflag[v2]][vflag[v1]] += e;
		}
		else {
			graph[vflag[v1]][vflag[v2]] = e;
			graph[vflag[v2]][vflag[v1]] = e;
		}
		getchar();
	}
	peoplenum = cnt;
	//process
	//Í³¼ÆÁ¬Í¨·ÖÁ¿
	cnt = 0;
	for (i=0;i<peoplenum;i++) 
	{
		if (visited[i] == 0)
		{
			dfs(i);
			if (membernum > 2 && edgenum > k)
			{
				result[cnt] = node;
				resultmem[cnt++] = membernum;
			}
		}
		membernum = 0;
		edgenum = 0;
		max = 0;
	}
	printf("%d\n", cnt);
	for (i = 0; i < cnt; i++)
	{
		name[2] = vnumTostr[result[i]] % indix + 'A';
		name[1] = (vnumTostr[result[i]] / indix) % indix + 'A';
		name[0] = (vnumTostr[result[i]] / indix / indix) % indix + 'A';
		name[3] = '\0';
		printf("%s %d\n", name, resultmem[i]);
	}
	//output
	return 0;
}
