//两个测试点没过
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node {
	int deep;
	int child[100];
	int childnum;
}list[100001];
int top = -1;
int cnt;
double price;
int n;
double max = -1;
double p, r;
void dfs(int n)
{
	if (list[n].childnum == 0)//叶子节点
	{
		price = pow(1 + r, list[n].deep-1)*p;
		if (price > max)
		{
			max = price;
			cnt = 1;
		}
		else if (price == max)
			cnt++;
	}
	for (int i = 0; i < list[n].childnum; i++)
	{
		list[list[n].child[i]].deep = list[n].deep + 1;
		dfs(list[n].child[i]);
	}
}
int main()
{
	scanf("%d%lf%lf", &n, &p, &r);
	r = r / 100;
	int i;
	for (i = 0; i < n; i++)
	{
		int v;
		scanf("%d", &v);
		if (v == -1)
			list[n].child[list[n].childnum++] = i;//根节点放在下标为n处
		else
			list[v].child[list[v].childnum++] = i;
	}
	dfs(n);
	printf("%.2lf %d", max, cnt);
}
