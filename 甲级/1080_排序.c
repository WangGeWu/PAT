#include<stdio.h>
#include<stdlib.h>
struct stunode
{
	int id;
	int Ge, Gi;
	int rank;//排名
	int school[5];//志愿学校
}stu[40001];//学生结构体
struct schnode
{
	int lastrank;//学校目前录取的最低排名
	int nownum;//目前录取的人数
	int maxnum;//计划录取的人数
	int stuid[40000];//已录取学生的id
}sch[100];//学校结构体
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
	qsort(stu, n, sizeof(struct stunode), cmp1);//按成绩排序
	for (i = 0; i < n; i++)//计算排名
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
	for (i = 0; i < n; i++)//计算录取
	{
		for (j = 0; j < k; j++)
		{
			if (sch[stu[i].school[j]].lastrank==stu[i].rank|| sch[stu[i].school[j]].maxnum>sch[stu[i].school[j]].nownum)//人数没招满或者该生的排名和学校录取的最低排名相同
			{
				sch[stu[i].school[j]].lastrank = stu[i].rank;//更新排名
				sch[stu[i].school[j]].stuid[sch[stu[i].school[j]].nownum++] = stu[i].id;//记录录取的学生
				break;
			}
		}
	}
	//output
	for (i = 0; i < m; i++)
	{
		qsort(sch[i].stuid, sch[i].nownum, sizeof(int), cmp2);//学生id排序后再输出
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
