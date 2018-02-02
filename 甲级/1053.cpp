#include<stdio.h>
#include<stdlib.h>
struct Tnode
{
	int weight;
	int numchild;
	int child[100];
}treenode[100];
int path[100];//保存访问节点i的父节点
void Print(int v)//递归打印路径
{
	if (path[v] != -1)
		Print(path[v]);
	if (path[v] == -1)
		printf("%d", treenode[v].weight);
	else
		printf(" %d", treenode[v].weight);
}
int cmp(const void *a, const void *b)
{
	return treenode[(*(int*)a)].weight > treenode[(*(int*)b)].weight;
}
int main()
{
	int W[100];
	int stack[100];
	int top = -1;
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	int i, j;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &treenode[i].weight);
		treenode[i].numchild = 0;
	}
	int r, num;
	for (i = 0; i < m; i++)
	{
		scanf("%d%d", &r, &num);
		treenode[r].numchild = num;
		for (j = 0; j < num; j++)
			scanf("%d", &treenode[r].child[j]);
		qsort(treenode[r].child, treenode[r].numchild, sizeof(int), cmp);//将子节点读入child数组，按子节点的权值从小到大对child数组排序
	}
	//process
	int node;
	path[0] = -1;
	W[0] = treenode[0].weight;
	stack[++top] = 0;
	//dfs
	while (top != -1)//栈不空
	{
		node = stack[top--];//出栈，因为之前已经排序，所以同一层中权值最大的先出栈
		if (W[node] == k&&treenode[node].numchild == 0)
		{
			Print(node);
			printf("\n");
		}
		for (i = 0; i < treenode[node].numchild; i++)
		{
			stack[++top] = treenode[node].child[i];//将节点的孩子压栈，权值小的先压入（后出）
			W[treenode[node].child[i]] = treenode[treenode[node].child[i]].weight + W[node];//更新权重
			path[treenode[node].child[i]] = node;//更新路径
		}
	}
	return 0;
}
