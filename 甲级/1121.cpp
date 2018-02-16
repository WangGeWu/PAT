#include<stdio.h>
#include<stdlib.h>
int couple[1000000] = {0};
int people[50000];
int result[10000];
int flag[50000] = {0};
int cmp(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}
int main()
{
	int n;
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		int v1, v2;
		scanf("%d%d", &v1, &v2);
		couple[v1] = couple[v2] = i + 1;//�����޵�coupleֵ��Ϊ���
	}
	int cnt1 = 0;
	int cnt2 = 0;
	int m;
	scanf("%d", &m);
	for (i = 0; i < m; i++)
	{
		int v;
		scanf("%d", &v);
		if (couple[v] == 0)
			result[cnt1++] = v;//�϶�����,ֱ�ӷ���������
		else
		{
			people[cnt2++] = v;//��ȷ���ķ���people����,���ڷ���
			flag[couple[v]]++;//��Ӧ��couple��1.������Ϊ1,����,Ϊ2�򲻵���
		}
	}
	for (i = 0; i < cnt2; i++)
	{
		if (flag[couple[people[i]]] == 1)
			result[cnt1++] = people[i];
	}
	qsort(result, cnt1, sizeof(int), cmp);
	if (cnt1 > 0)
	{
		printf("%d\n%05d",cnt1,result[0]);
		for (i = 1; i < cnt1; i++)
		{
			printf(" %05d", result[i]);
		}
	}
	else
		printf("0\n");
	return 0;
}