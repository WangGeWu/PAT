/*
 *��������תǰ����޸ġ�ǰ��Ҳ��������dfs��
 *�ݹ�ʱ���������ϸ��ڵ����ȡ�
 *��ݹ��������������ȼ��Ǹ��ڵ�����+1
 *�ýṹ��洢ÿ��Ľڵ㣬�����±�Ϊ��ȡ����ʱ���������
 */
#include<stdio.h>
int inorder[31];
int postorder[31];
int preorder[31];
struct Tnode
{
	int node_num;
	int node[31];//�ڵ�ֵ
}list[31];//�±�������
void InPostToPre(int in,int post,int n,int deep)/*in����������ʼ�±꣬post����������ʼ�±꣬deep���ڵ�����*/
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