#include<stdio.h>
#include<math.h>
struct node
{
	int deep;
	int child[160];
	int childnum;
}tree[100005];
double min =999999999.9;
double price, p, r;
int num=0;
void dfs(int n)
{
	if (tree[n].childnum == 0)
	{
		price = p*pow(1+r, tree[n].deep);
		if (price < min)
		{
			min = price;
			num = 1;
		}
		else if (price == min)
			num++;
	}
	for (int i = 0; i < tree[n].childnum; i++)
	{
		tree[tree[n].child[i]].deep = tree[n].deep + 1;
		dfs(tree[n].child[i]);
	}
}
int main()
{
	int n;
	int i, j;
	scanf("%d%lf%lf", &n, &p, &r);;
	r /= 100;
	for (i = 0; i < n; i++)
	{
		int m;
		scanf("%d", &m);
		tree[i].childnum = m;
		for (j = 0; j < m; j++)
			scanf("%d", &tree[i].child[j]);
	}
	dfs(0);
	printf("%.4lf %d", min, num);
	return 0;
}