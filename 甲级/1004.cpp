#include<stdio.h>
#include<stdlib.h>
#define Inf 100
#define Max 200
int main()
{
	int queue[999];
	int x;
	int front = 0;
	int rear = 0;
	int Num_node,M,num;
	int i,m,flag;
	int root;
	int deep[Max];
	int tree[Max];//����ڵ�洢��Ԫ���Ǵ��±�ڵ�ĸ��ڵ��±꣬����A[1]=2�����ǽڵ�1�ĸ��ڵ��ǽڵ�2�����ڵ��ֵΪ-1
	int cnt[Max];
	int parent,child;
	scanf("%d", &Num_node);
	for (i = 1; i < Max; i++)
	{
		cnt[i] = 0;
		deep[i] = 0;
	}
	for(i=1;i<Max;i++)
		tree[i] = -2;
	scanf("%d", &M);
	if (Num_node == 0)
	{
		printf("%d\n",0);
		return 0;
	}
	for (m=0; m < M; m++)
	{
		scanf("%d", &parent);
		if (tree[parent] ==-2)
		{
			tree[parent] = -1;
		}
		scanf("%d", &num);
		for (i = 0; i < num; i++)
		{
			scanf("%d", &child);
			tree[child] = parent;
		}
	}
	for (i = 1; i <= Max; i++)
	{
		if (tree[i] == -1)break;
	}
	x = i;
	deep[x] = 1;
	//���(�������)
	queue[++rear] = x;
	while(front!=rear)
	{
		flag = -1;
	//����
		x = queue[++front];
		for (i = 1; i <= Max; i++)
		{
			if (tree[i] == x)//�����ӽڵ�
			{
				flag = 1;
				//���
				deep[i] = deep[x] + 1;//�ӽڵ����=���ڵ�����+1
				queue[++rear] = i;
			}
		}
		if (flag == -1)cnt[deep[x]]++;
	}
	i = 1;
	int max = 0;
	for (i = 1; i <Max; i++)
	{
		if (deep[i] != 0)
		{
			if (deep[i] > max)
				max = deep[i];
		}
	}
	for(i=1;i<max;i++)
	{
		printf("%d ", cnt[i]);
	}
	printf("%d\n", cnt[i]);
	return 0;
}