#include<stdio.h>
#include<stdlib.h>
struct Tnode
{
	int weight;
	int numchild;
	int child[100];
}treenode[100];
int path[100];//������ʽڵ�i�ĸ��ڵ�
void Print(int v)//�ݹ��ӡ·��
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
		qsort(treenode[r].child, treenode[r].numchild, sizeof(int), cmp);//���ӽڵ����child���飬���ӽڵ��Ȩֵ��С�����child��������
	}
	//process
	int node;
	path[0] = -1;
	W[0] = treenode[0].weight;
	stack[++top] = 0;
	while (top != -1)//ջ����
	{
		node = stack[top--];//��ջ����Ϊ֮ǰ�Ѿ���������ͬһ����Ȩֵ�����ȳ�ջ
		if (W[node] == k&&treenode[node].numchild == 0)
		{
			Print(node);
			printf("\n");
		}
		for (i = 0; i < treenode[node].numchild; i++)
		{
			stack[++top] = treenode[node].child[i];//���ڵ�ĺ���ѹջ��ȨֵС����ѹ�루�����
			W[treenode[node].child[i]] = treenode[treenode[node].child[i]].weight + W[node];//����Ȩ��
			path[treenode[node].child[i]] = node;//����·��
		}
	}
	return 0;
}