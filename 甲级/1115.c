//dfs+build bst
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int deep;
	int key;
	struct node* left;
	struct node* right;
};
int deep_node_num[1002];
struct node* build(struct node* t, int n)
{
	if (!t)
	{
		t = (struct node*)malloc(sizeof(struct node));
		t->key = n;
		t->left = t->right = NULL;
	}
	else
	{
		if (n > t->key)t->right = build(t->right, n);
		else t->left = build(t->left, n);
	}
	return t;
}
void dfs(struct node* t)
{
	if (t->left)
	{
		t->left->deep = t->deep + 1;
		deep_node_num[t->left->deep]++;
		dfs(t->left);
	}
	if (t->right)
	{
		t->right->deep = t->deep + 1;
		deep_node_num[t->right->deep]++;
		dfs(t->right);
	}
}
int main()
{
	int n;
	int i;
	struct node* root = NULL;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		int data;
		scanf("%d", &data);
		root=build(root,data);
	}
	deep_node_num[0] = 1;
	root->deep = 0;
	dfs(root);
	if (n == 1) 
	{
		printf("1 + 0 = 1"); 
		return 0;
	}
	for (i = 0; i < n; i++)
		if (deep_node_num[i + 2] == 0)
			break;
	printf("%d + %d = %d", deep_node_num[i + 1], deep_node_num[i], deep_node_num[i + 1] + deep_node_num[i]);
	return 0;
}
