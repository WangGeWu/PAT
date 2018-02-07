//两个点没AC
//数据量大的时候，递归层数变多，会导致段错误
//建议使用bfs
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double cnt = 0;
int n;
double p, r;
struct node
{
	double num;
	int child[100];
	int childnum;
	int deep;
}tree[100001];
void dfs(int v)
{ 
	if (tree[v].childnum == 0)
	{
		cnt += tree[v].num * pow(1 + r, tree[v].deep);
		return;
	}
	for (int i = 0; i < tree[v].childnum; i++)
	{
		tree[tree[v].child[i]].deep = tree[v].deep + 1;
		dfs(tree[v].child[i]);
	}
}
int main()
{
	int i, j;
	scanf("%d%lf%lf", &n, &p, &r);
	r = r / 100;
	for (i = 0; i < n; i++)
	{
		int m;
		scanf("%d", &m);
		tree[i].childnum = m;
		for (j = 0; j < m; j++)
		{
			scanf("%d",&tree[i].child[j]);
		}
		if (m == 0)
			scanf("%lf", &tree[i].num);
	}
	dfs(0);
	cnt =cnt*p;
	printf("%.1lf", cnt);
	return 0;
}