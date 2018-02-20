/*
 *后序中序转前序的修改。前序也就是树的dfs。
 *递归时，参数加上根节点的深度。
 *则递归的左右子树的深度即是父节点的深度+1
 *用结构体存储每层的节点，数组下标为深度。输出时方便输出。
 */
#include<stdio.h>
int inorder[31];
int postorder[31];
int preorder[31];
struct Tnode
{
	int node_num;
	int node[31];//节点值
}list[31];//下标代表深度
void InPostToPre(int in,int post,int n,int deep)/*in中序数组起始下标，post后续数组起始下标，deep根节点的深度*/
{
	if (n <= 0)
		return;
	int i = in;
	while (inorder[i] != postorder[post + n - 1])i++;
	list[deep].node[list[deep].node_num++] = inorder[i];
	int left_num = i - in; int right_num = n - i + in - 1;
	InPostToPre(in, post,left_num, deep + 1);
	InPostToPre(i + 1, post + left_num, right_num, deep + 1);
}
int main()
{
	int n; int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &inorder[i]);
	for (i = 0; i < n; i++)
		scanf("%d", &postorder[i]);
	InPostToPre(0,0,n,1);
	int cnt = 0;
	for (i = 1; i < 31; i++)
	{
		if (i % 2 == 0)
		{
			for (int j = 0; j < list[i].node_num; j++)
			{
				if (cnt == 0)
					printf("%d", list[i].node[j]);
				else
					printf(" %d", list[i].node[j]);
				cnt++;
			}
		}
		else
		{
			for (int j = list[i].node_num - 1; j >= 0; j--)
			{
				if (cnt == 0)
					printf("%d", list[i].node[j]);
				else
					printf(" %d", list[i].node[j]);
				cnt++;
			}
		}
	}
	return 0;
}
