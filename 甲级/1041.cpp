#include<stdio.h>
#include<stdlib.h>
/*
   *��flag����洢�������ֳ��ֵĴ���
   *��ΪҪ�������һ��unique����
   *���԰��������ݵ�˳���ѯflag����
   *�����һ��unique��
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