#include<stdio.h>
struct node
{
	char key[11];
	int left, right;
}tree[21];
int root;
int flag[21];
void inorder(int t)//递归中序
{
	if (t != -1)
	{
		if (!(tree[t].left == -1 && tree[t].right == -1)&&t!=root)//t节点有孩子且t不是树的根root
			printf("(");
		inorder(tree[t].left);
		printf("%s", tree[t].key);
		inorder(tree[t].right);	
		if (!(tree[t].left == -1 && tree[t].right == -1)&&t!=root)
			printf(")");
	}
}
int main()
{
	int n;
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%s%d%d", &tree[i].key, &tree[i].left, &tree[i].right);
		flag[tree[i].left] = flag[tree[i].right] = 1;
	}
	for (i = 1; i <= n; i++)
		if (flag[i] == 0)
			break;
	root = i;
	inorder(root);
	return 0;
}
