#include<stdio.h>
#include<stdlib.h>
/*
    *结构体存储每个学生的科目成绩，成绩的名次，
	*最好名次对应的科目数组下标和学生的ID，
	*存储时，按A>C>M>E的顺序存储，即下标0存储A成绩、名次，
	下标1存储C成绩/名次，以此类推。可以减少寻找学生最好名次代码的复杂度
*/
struct node
{
	int best;//最好科目的下标
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
		stu[i].score[0] = (int)((stu[i].score[1] + stu[i].score[2] + stu[i].score[3]) / 3);//四舍五入
	}
	//process
	//依次对各个科目进行成绩排序，计算学生对应科目的名次
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
	//按A>C>M>E的规则找出每个学生最好的名次
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