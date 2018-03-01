//因为不知道每个节点的最多有多少子节点，所以在结构体内开辟孩子节点的数组时，很难把握开辟的大小，所以用了C++里面的vector
#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;
struct node
{
	int deep;
	vector<int>child;
}tree[100005];
double Min = 999999999.9;
double price, p, r;
int num = 0;
void dfs(int n)
{
	if (tree[n].child.size()== 0)
	{
		price = p*pow(1 + r, tree[n].deep);
		if (price < Min)
		{
			Min = price;
			num = 1;
		}
		else if (price == Min)
			num++;
	}
	for (int i = 0; i < tree[n].child.size(); i++)
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
		for (j = 0; j < m; j++)
		{
			int node;
			scanf("%d", &node);
			tree[i].child.push_back(node);
		}
	}
	dfs(0);
	printf("%.4lf %d", Min, num);
	return 0;
}
