#include<stdio.h>
struct node {
	int deep;
	int childnum;
	int child[100];
}list[100];
int max = 0;//记录最大节点数
int node;//记录最多节点的层数
int deepman[100];//记录每层节点数
void dfs(int n)
{
	deepman[list[n].deep]++;
	if (deepman[list[n].deep] > max)
	{
		node = list[n].deep;
		max = deepman[list[n].deep];
	}
	for (int i = 0; i < list[n].childnum; i++)
	{
		list[list[n].child[i]].deep = list[n].deep + 1;
		dfs(list[n].child[i]);
	}
}
int main()
{
	int i,j;
	int n, m;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++)
	{
		int root, num;
		scanf("%d%d", &root, &num);
		for (j = 0; j < num; j++)
		{
			int v;
			scanf("%d", &v);
			list[root].child[list[root].childnum++] = v;
		}
	}
	list[1].deep = 1;
	dfs(1);
	printf("%d %d", max, node);
	return 0;
}
