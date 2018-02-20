#include<stdio.h>
struct node
{
	int left, right;
}tree[10];
int queue[20];
int front = -1, rear = -1;
int hash[20];
int flag = 0;
void bfs(int n)
{
	queue[++rear] = n;
	while (rear != front)
	{
		int node = queue[++front];
		if (flag == 0)
		{
			printf("%d", node);
			flag = 1;
		}
		else
			printf(" %d", node);
		if (tree[node].left != -1)queue[++rear] = tree[node].left;
		if (tree[node].right != -1)queue[++rear] = tree[node].right;
	}
}
void inorder(int n)
{
	if (tree[n].left != -1)inorder(tree[n].left);
	if (flag == 0)
	{
		printf("%d", n);
		flag = 1;
	}
	else
		printf(" %d", n);
	if (tree[n].right != -1)inorder(tree[n].right);
}
int main()
{
	int i;
	int n;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		char l, r;
		getchar();
		scanf("%c %c", &l, &r);
		if (r != '-')
		{
			tree[i].left = r - '0';
			hash[tree[i].left] = 1;
		}
		else
			tree[i].left = -1;
		if (l != '-')
		{
			tree[i].right = l - '0';
			hash[tree[i].right] = 1;
		}
		else
			tree[i].right = -1;
	}
	for (i = 0; i < n; i++)
		if (hash[i] == 0)
			break;
	bfs(i);
	printf("\n");
	flag = 0;
	inorder(i);
	return 0;
}
