#include<stdio.h>
#include<stdlib.h>
/*
   *用flag数组存储读入数字出现的次数
   *因为要求输出第一个unique的数
   *所以按读入数据的顺序查询flag数组
   *输出第一个unique数
*/
int main()
{
	int *num;
	int flag[10001] = {0};
	int n;
	int i;
	scanf("%d", &n);
	num = (int*)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
		flag[num[i]]++;
	}
	for (i = 0; i < n; i++)
	{
		if (flag[num[i]] == 1)
		{
			printf("%d\n", num[i]);
			return 0;
		}
	}
	printf("None\n");
	return 0;
}