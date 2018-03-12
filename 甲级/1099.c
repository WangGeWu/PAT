#include<stdio.h>
#include<stdlib.h>
struct node
{
	int key;
	int left, right;
}tree[100];
int num[100];
int front = -1, rear = -1;
int queue[100];
int cmp(const void*a, const void *b)
{
	return *(int*)a - *(int*)b;
}
int find_node_num(int t)//Çó¸ùÎªtµÄÊ÷µÄ½Úµã×ÜÊý
{
	if (t == -1)
		return 0;
	return find_node_num(tree[t].left) + find_node_num(tree[t].right) + 1;
}
void build(int t,int start,int end)
{
	int x=find_node_num(tree[t].left);
	tree[t].key = num[start+x];
	if (tree[t].left != -1)
		build(tree[t].left, start, start + x - 1);
	if (tree[t].right != -1)
		build(tree[t].right, start + x+1, end);
}
void bfs(int t) 
{
	queue[++rear] = t;
	while (rear != front)
	{
		int node = queue[++front];
		if (rear == 0)
			printf("%d", tree[node].key);
		else
			printf(" %d", tree[node].key);
		if (tree[node].left != -1)
			queue[++rear] = tree[node].left;
		if (tree[node].right != -1)
			queue[++rear] = tree[node].right;
	}
}
int main()
{
	int n;
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d%d", &tree[i].left, &tree[i].right);
	for (i = 0; i < n; i++)
		scanf("%d", &num[i]);
	qsort(num, n, sizeof(int), cmp);
        build(0,0,n-1);
	bfs(0);
	return 0;
}
