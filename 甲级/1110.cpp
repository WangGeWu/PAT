//一个测试点没过
#include<stdio.h>
#include<stdlib.h>
int hash[21];
struct node {
	int left, right;
}tree[21];
int queue[100];
int front = -1, rear = -1;
int n;
void bfs(int t)
{
	int cnt = 0;
	int lastnode;
	queue[++rear] = t;
	while (rear != front)
	{
		int node = queue[++front];
		if (node != -1)
		{
		    lastnode = node;
			cnt++;
		}
		else
		{
			if (cnt == n)
				printf("YES %d", lastnode);
			else
				printf("NO %d", t);
			return;
		}
		queue[++rear] = tree[node].left;
		queue[++rear] = tree[node].right;
	}
}
int main()
{
	int i, j;
	char s1[3];
	char s2[3];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%s%s", s1, s2);
		if (s1[0] == '-')
			tree[i].left = -1;
		else
		{
			tree[i].right = atoi(s1);
			hash[atoi(s1)] = 1;
		}
		if (s2[0] == '-')
			tree[i].left = -1;
		else
		{
			tree[i].right = atoi(s2);
			hash[atoi(s2)] = 1;
		}
	}
	for (i = 0; i < n; i++)
		if (hash[i] == 0)
			break;
	int root = i;
	bfs(root);
	return 0;
}