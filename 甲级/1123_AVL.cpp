#include<stdio.h>
#include<stdlib.h>
int flag = 1;//标记是否是完全二叉树
typedef struct node
{
	int key;
	struct node* left;
	struct node* right;
}*tree;
int n;
int max(int a, int b)
{
	return a > b ? a : b;
}
int Tree_height(tree root)
{
	if (!root)
		return 0;
	return max(Tree_height(root->left), Tree_height(root->right)) + 1;
}
tree ToLL(tree root)
{
	tree p = root->left;
	root->left = root->left->right;
	p->right = root;
	return p;
}
tree ToRR(tree root)
{
	tree p = root->right;
	root->right = root->right->left;
	p->left = root;
	return p;
}
tree ToLR(tree root)
{
	root->left=ToRR(root->left);
	root = ToLL(root);
	return root;
}
tree ToRL(tree root)
{
	root->right = ToLL(root->right);
	root = ToRR(root);
	return root;
}
tree Build(tree root, int k)
{
	if (!root)
	{
		tree t = (tree)malloc(sizeof(struct node));
		t->left = t->right = NULL;
		t->key = k;
		root = t;
	}
	else
	{
		if (root->key < k)
		{
			root->right = Build(root->right, k);
			if (Tree_height(root->right) - Tree_height(root->left) == 2)
			{
				if (root->right->key < k)
					root = ToRR(root);
				else
					root = ToRL(root);
			}
		}
		else
		{
			root->left = Build(root->left, k);
			if (Tree_height(root->left) - Tree_height(root->right) == 2)
			{
				if (root->left->key > k)
					root = ToLL(root);
				else
					root = ToLR(root);
			}
		}
	}
	return root;
}
void bfs(tree root)
{
	tree queue[100];
	int front = -1, rear = -1;
	queue[++rear] = root;
	int cnt = 0;
	while (rear != front)
	{
		tree node = queue[++front];
		cnt++;
		if (cnt == 1)
			printf("%d", node->key);
		else
			printf(" %d", node->key);
		if (node->left)
			queue[++rear] = node->left;
		else
		{
			if (rear - front+cnt!= n)//入队的总结点数不等于n时，说明还要节点没入队，但遇到了空节点，因此不是完全二叉树
				flag = 0;
		}
		if (node->right)
			queue[++rear] = node->right;
		else
		{
			if (rear - front+ cnt != n)
				flag = 0;
		}
	}
}
int main()
{
	int i;
	scanf("%d", &n);
	tree root=NULL;
	for (i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);
		root=Build(root,k);
	}
	bfs(root);
	printf("\n");
	if (flag)
		printf("YES");
	else
		printf("NO");
	return 0;
}