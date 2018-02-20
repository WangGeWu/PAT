#include<stdio.h>
#include<stdlib.h>
//栈模拟
int main()
{
	int flag = 1;
	int stack[1001];
	int top;//栈顶下标
	int num;//栈中元素个数
	int m, n, k;
	int test[1001];
	scanf("%d %d %d", &m, &n, &k);
	int i, j;
	int cnt;
	for (i = 0; i < k; i++)
	{
		top = -1;//清空栈
		flag = 1;
		cnt = 1;
		num = 0;
		for (j = 0; j < n; j++)
		{
			scanf("%d", &test[j]);
		}
		j = 0;
		while(j<n)
		{
			if (num!=0&&stack[top] == test[j])//栈不空
			{
				//pop
				top--;
				num--;
				j++;
			}
			else if ((num==0||stack[top] != test[j])&&num<m&&cnt<=n)
			{
				//push
				stack[++top] = cnt++;
				num++;
			}
			else if (num>=m||cnt>n)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 0)printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
