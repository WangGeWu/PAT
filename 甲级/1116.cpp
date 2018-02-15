#include<stdio.h>
int flag1[10000];//标记是否存在
int flag2[10000];//标记是否访问过
int stu[10000];
int judge(int n)
{
	for (int i = 2; i*i <= n; i++)
		if (n%i == 0)
			return 0;
	return 1;
}
int main()
{
	int n, m;
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		int v;
		scanf("%d", &v);
		stu[v] = i + 1;
		flag1[v] = 1;
	}
	scanf("%d", &m);
	for (i = 0; i < m; i++)
	{
		int v;
		scanf("%d", &v);
		if (flag1[v] == 1 && flag2[v] == 0)
		{
			flag2[v] = 1;
			if (stu[v] == 1)
				printf("%04d: Mystery Award\n",v);
			else if (judge(stu[v]))
				printf("%04d: Minion\n",v);
			else
				printf("%04d: Chocolate\n",v);
		}
		else if (flag1[v] == 0)
			printf("%04d: Are you kidding?\n",v);
		else
		{
			printf("%04d: Checked\n",v);
		}
	}
	return 0;
}