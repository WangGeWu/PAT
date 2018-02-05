#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int key;
	struct node* left;
	struct node* right;
}*Tree;
int max(int x, int y)
{
	return x > y ? x : y;
}
Tree ToRR(Tree t)//����Ľڵ���t������������������
{
	Tree node = t->right;
	t->right = node->left;
	node->left = t;
	return node;
}
Tree ToLL(Tree t)
{
	Tree node = t->left;
	t->left = node->right;
	node->right = t;
	return node;
}
Tree ToRL(Tree t)//����Ľڵ���t������������������
{
	t->right = ToLL(t->right);
	return ToRR(t);
}
Tree ToLR(Tree t)
{
	t->left = ToRR(t->left);
	return ToLL(t);
}
int high(Tree t)//������t�ĸ�
{
	if (!t)
		return 0;
	else
		return max(high(t->left), high(t->right))+1;
}
Tree insert(int x,Tree t)
{
	if (!t)
	{
		Tree node = (Tree)malloc(sizeof(struct node));
		node->key = x;
		node->left = node->right = NULL;
		t=node;
	}
	else if (t->key > x)
	{
		t->left=insert(x, t->left);
		if (high(t->left) - high(t->right) == 2)//��������
		{
			if (t->left->key > x)//x������t����������������
				t=ToLL(t);
			else
				t=ToLR(t);
		}
	}
	else
	{
		t->right = insert(x, t->right);
		if (high(t->right) - high(t->left) == 2)//��������
		{
			if (t->right->key < x)//x������t����������������
				t=ToRR(t);
			else
				t=ToRL(t);
		}
	}
	return t;
}
int main()
{
	int i, n;
	scanf("%d", &n);
	Tree root = NULL;
	for (i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		root=insert(x,root);
	}
	printf("%d",root->key);
}