#include<stdio.h>
#include<stdlib.h>
struct stunode
{
	int id;
	int Ge, Gi;
	int rank;//����
	int school[5];//־ԸѧУ
}stu[40001];//ѧ���ṹ��
struct schnode
{
	int lastrank;//ѧУĿǰ¼ȡ���������
	int nownum;//Ŀǰ¼ȡ������
	int maxnum;//�ƻ�¼ȡ������
	int stuid[40000];//��¼ȡѧ����id
}sch[100];//ѧУ�ṹ��
int cmp1(const void *a, const void *b)
{
	if (((struct stunode*)a)->Ge + ((struct stunode*)a)->Gi != ((struct stunode*)b)->Ge + ((struct stunode*)b)->Gi)
		return (((struct stunode*)a)->Ge + ((struct stunode*)a)->Gi < ((struct stunode*)b)->Ge + ((struct stunode*)b)->Gi);
	else
		return(((struct stunode*)a)->Ge < ((struct stunode*)b)->Ge);
}
int cmp2(const void*a, const void *b)
{
	return *(int*)a > *(int*)b;
}
int main()
{
	int i, j;
	int n, m, k;
	//input
	scanf("%d%d%d", &n, &m, &k);
	for (i = 0; i < m; i++)
		scanf("%d", &sch[i].maxnum);
	for (i = 0; i < n; i++)
	{
		stu[i].id = i;
		scanf("%d%d", &stu[i].Ge, &stu[i].Gi);
		for (j = 0; j < k; j++)
			scanf("%d", &stu[i].school[j]);
	}
    //process
	qsort(stu, n, sizeof(struct stunode), cmp1);//���ɼ�����
	for (i = 0; i < n; i++)//��������
	{
		if (i == 0)
		{
			stu[i].rank = 1;
		}
		else
		{
			if ((stu[i].Ge + stu[i].Gi == stu[i - 1].Ge + stu[i - 1].Gi)&&(stu[i].Ge == stu[i - 1].Ge))
				stu[i].rank = stu[i - 1].rank;
			else
				stu[i].rank = i + 1;
		}
	}
	for (i = 0; i < n; i++)//����¼ȡ
	{
		for (j = 0; j < k; j++)
		{
			if (sch[stu[i].school[j]].lastrank==stu[i].rank|| sch[stu[i].school[j]].maxnum>sch[stu[i].school[j]].nownum)//����û�������߸�����������ѧУ¼ȡ�����������ͬ
			{
				sch[stu[i].school[j]].lastrank = stu[i].rank;//��������
				sch[stu[i].school[j]].stuid[sch[stu[i].school[j]].nownum++] = stu[i].id;//��¼¼ȡ��ѧ��
				break;
			}
		}
	}
	//output
	for (i = 0; i < m; i++)
	{
		qsort(sch[i].stuid, sch[i].nownum, sizeof(int), cmp2);//ѧ��id����������
		for (j = 0; j < sch[i].nownum; j++)
		{
			if (j != 0)
				printf(" ");
			printf("%d", sch[i].stuid[j]);
		}
		printf("\n");
	}
	return 0;
}