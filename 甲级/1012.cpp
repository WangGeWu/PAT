#include<stdio.h>
#include<stdlib.h>
/*
    *�ṹ��洢ÿ��ѧ���Ŀ�Ŀ�ɼ����ɼ������Σ�
	*������ζ�Ӧ�Ŀ�Ŀ�����±��ѧ����ID��
	*�洢ʱ����A>C>M>E��˳��洢�����±�0�洢A�ɼ������Σ�
	�±�1�洢C�ɼ�/���Σ��Դ����ơ����Լ���Ѱ��ѧ��������δ���ĸ��Ӷ�
*/
struct node
{
	int best;//��ÿ�Ŀ���±�
	int id;
	int score[4];
	int rank[4];
}stu[2001];
int cnt = 0;
int cmp(const void *a, const void *b)
{
	return ((struct node*)b)->score[cnt] - ((struct node*)a)->score[cnt];
}
int main()
{
	char a[4] = { 'A','C','M','E' };
	int n, m;
	int i, j;
	//input
	scanf("%d %d", &n,&m);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &stu[i].id);
		scanf("%d", &stu[i].score[1]);
		scanf("%d", &stu[i].score[2]);
		scanf("%d", &stu[i].score[3]);
		stu[i].score[0] = (int)((stu[i].score[1] + stu[i].score[2] + stu[i].score[3]) / 3);//��������
	}
	//process
	//���ζԸ�����Ŀ���гɼ����򣬼���ѧ����Ӧ��Ŀ������
	while (cnt < 4)
	{
		qsort(stu, n, sizeof(struct node), cmp);
		for (i = 0; i < n; i++)
		{
			if (i == 0)
			{
				stu[i].rank[cnt] = 1;
			}
			else if (stu[i].score[cnt] == stu[i - 1].score[cnt])
			{
				stu[i].rank[cnt] = stu[i - 1].rank[cnt];
			}
			else
				stu[i].rank[cnt] = i+1;
		}
		cnt++;
	}
	//��A>C>M>E�Ĺ����ҳ�ÿ��ѧ����õ�����
	int min;
	for (i = 0; i < n; i++)
	{
		min = 9999;
		for (j = 0; j < 4; j++)
		{
			if (stu[i].rank[j] < min)
			{
				min = stu[i].rank[j];
				stu[i].best = j;
			}
		}
	}
	//output
	int name;
	for (i = 0; i < m; i++)
	{
		scanf("%d", &name);
		for (j = 0; j < n; j++)
		{
			if (name == stu[j].id)
			{
				printf("%d %c\n", stu[j].rank[stu[j].best], a[stu[j].best]);
				break;
			}
		}
		if (j == n)
			printf("N/A\n");
	}
	return 0;
}