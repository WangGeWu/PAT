#include<stdio.h>
int num[100000];
int pos[100000];
int main()
{
	int cnt = 0;
	int i;
	int n;
	int node;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
		pos[num[i]] = i;//记录num[i]存储的位置,否则会超时
	}
	int flag;
	int index=0;
	node = pos[0];//node记录0所在下标
	while (1)
	{
		if (node == 0)//如果0在下标0处，交换0和第一个不在其位置的数
		{
			flag = 0;
			for (i = index; i < n; i++)
			{
				if (num[i] != i)
				{
					flag = 1;
					index = i;//index存储第一个不在其位置的数的下标,下一次循环时，从index后开始循环
					break;
				}
			}
			if (flag == 0)break;
			num[node] = num[i];//交换
			pos[num[i]] = node;//更新pos
			num[i] = 0;//交换
			pos[0] = i;//更新pos
			node = i;//更新node
			cnt++;
		}
		else
	    {
			num[pos[node]] = 0;
			pos[0] = pos[node];
			num[node] = node;
			pos[node] = node;
			node = pos[0];
			cnt++;
		}
    }
	printf("%d", cnt);
	return 0;
}
