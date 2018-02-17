#include<stdio.h>
#include<stdlib.h>
int count[50001] = {0};//��¼ÿ���������ֵĴ���
int k;
int rank[11] = {0};//��¼��ǰӦ���Ƽ���k��ֵ
int cmp(const void *a, const void *b)
{
	if (count[*(int*)a] != count[*(int*)b])
		return count[*(int*)b] - count[*(int*)a];
	else
		return *(int*)a - *(int*)b;
}
int find(int n)
{
	for (int i = 0; i < k; i++)
		if (rank[i] == n)
			return 1;
	return 0;
}
int main()
{
	int n;
	scanf("%d%d", &n, &k);
	int i, j;
	for (i = 0; i < n; i++)
	{
		int data;
		scanf("%d", &data);
		count[data]++;
		if (i != 0)
		{
			printf("%d:", data);
			for (j = 0; j < k; j++)
			{
				if (rank[j] != 0)
					printf(" %d", rank[j]);
			}
			printf("\n");
		}
		if(find(data))//���εļ���������ϴ�rank�����У����������򼴿�
			qsort(rank, k, sizeof(int), cmp);
		else if (count[data] > count[rank[k - 1]] || (count[data] == count[rank[k - 1]] && data < rank[k - 1]))//�������rank�����У���rank�������һλ�Ƚϣ���������ʱ�滻���һ�������½�������
		{
			rank[k - 1] = data;
			qsort(rank, k, sizeof(int), cmp);
		}
	}
	return 0;
}