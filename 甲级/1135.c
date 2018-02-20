#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int pre_order[30];
int n;
int flag;
typedef struct node
{
	int black_num;
	int key;
	struct node* left;
	struct node* right;
}*tree;
tree build(tree root,int k)
{
	if (!root)
	{
		tree t = (tree)malloc(sizeof(struct node));
		t->key = k;
		t->left = t->right = NULL;
		root = t;
	}
	else
	{
		if (abs(root->key) > abs(k))
			root->left = build(root->left, k);
		else
			root->right = build(root->right, k);
	}
	return root;
}
void dfs1(tree root)
{
	if (root)
	{
		if (root->key < 0)
		{
			if (root->left)
				if (root->left->key < 0)
					flag = 0;
			if (root->right)
				if (root->right->key < 0)
					flag = 0;
		}
		 dfs1(root->left);
		 dfs1(root->right);
	}
}
int dfs2(tree root) 
{
	if (root)
	{
		int l = dfs2(root->left);
		int r = dfs2(root->right);
		if (l != r)
			flag = 0;
		if (root->key > 0)
			return l  + 1;
		else
			return l ;
	}
	else
		return 1;
}
void judge(int t,int num)
{
	if (num <= 0)
		return;
	int i = t + 1;
	int j = t+num - 1;
	while (i <= j && abs(pre_order[i]) < abs(pre_order[t]))i++;
	while (j > t&&abs(pre_order[j]) >= abs(pre_order[t]))j--;
	if (i-j == 1)
	{
		judge(t + 1,i-t-1 );
		judge(i, t + num - i);
	}
	else
		flag = 0;
}
int main()
{
	int k;
	int i, j;
	scanf("%d", &k);
	for (i = 0; i < k; i++)
	{
		tree root=NULL;
		flag = 1;
		scanf("%d", &n);
		for (j = 0; j < n; j++)
		{
			scanf("%d", &pre_order[j]);
			root=build(root, pre_order[j]);
		}
		if (pre_order[0] < 0)//判断根节点是否为黑
			flag = 0;
		judge(0, n);//是否是二叉搜索树
	    dfs1(root);//是否满足红节点的子节点为黑节点
	    dfs2(root);//是否满足到叶子节点所经过的黑节点个数相等
		if (flag)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
