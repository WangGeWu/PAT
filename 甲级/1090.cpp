//因为不知道每个节点的最多有多少子节点，所以在结构体内开辟孩子节点的数组时，很难把握开辟的大小，所以用了C++里面的vector
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<vector>
using namespace std;
struct node {
	int deep;
	vector<int>child;
}list[100001];
int top = -1;
int cnt;
double price;
int n;
double Max = -1;
double p, r;
void dfs(int n)
{
	if (list[n].child.size() == 0)//叶子节点
	{
		price = pow(1 + r, list[n].deep - 1)*p;
		if (price > Max)
		{
			Max = price;
			cnt = 1;
		}
		else if (price == Max)
			cnt++;
	}
	for (int i = 0; i < list[n].child.size(); i++)
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
			list[n].child.push_back(i);//根节点放在下标为n处
		else
			list[v].child.push_back(i);
	}
	dfs(n);
	printf("%.2lf %d", Max, cnt);
}
