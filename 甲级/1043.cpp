#include<stdio.h>
#include<stdlib.h>
int	Pro[2001];
int Post[2001];
int cnt = 0;
int flag = 1;//标记是否是满足搜索树的前序遍历顺序
void judge1(int root, int num)//root为根节点下标，num为需要处理的节点数
{
	if (num<=0)return;
	int i = root + 1, j = root+num-1;
	while (Pro[root] > Pro[i] && i <= j)i++;
	while (Pro[root] <= Pro[j] && j>root)j--;
	if (i - j == 1)
	{
		judge1(root + 1, i-(root+1));
		//Post[cnt++]=Pro[root] 如果记录放在此处，则为中序遍历的顺序
		judge1(i, num-1-(i-(root+1)));
		Post[cnt++] = Pro[root];//左右子树处理完后，将根节点放入数组，即后序遍历的顺序
	}
	else
		flag = 0;
}
void judge2(int root, int num)//镜像树
{
	if (num<=0)return;
	int i = root + 1, j = root+num-1;
	while (Pro[root] <= Pro[i] && i <= j)i++;
	while (Pro[root] > Pro[j] && j>root)j--;
	if (i - j == 1)
	{
		judge2(root + 1,i-(root+1));
		judge2(i, num-1-(i-(root+1)));
		Post[cnt++] = Pro[root];
	}
	else
		flag = 0;
}
int main()
{
	int n;
	int i;
	//input
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &Pro[i]);
	//judge
	judge1(0, n);
	if (flag)
	{
		printf("YES\n");
		printf("%d", Post[0]);
		for (i = 1; i<n; i++)
		{
			printf(" %d", Post[i]);
		}
	}
	else
	{
		cnt = 0;
		flag = 1;
		judge2(0, n);
		if (flag)
		{
			printf("YES\n");
			printf("%d", Post[0]);
			for (i = 1; i<n; i++)
			{
				printf(" %d", Post[i]);
			}
		}
		else
		{
			printf("NO");
		}
	}
	return 0;
}