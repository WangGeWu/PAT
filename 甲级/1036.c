#include<stdio.h>
#include<string.h>
/*
  *用两个数组保存男女不同的信息，
  *分别找出最大和最小值
  */
struct mannode
{
	char name[11];
	char id[11];
	int grade;
}men[101];
struct womennode
{
	char name[11];
	char id[11];
	int grade;
}women[101];
int main()
{
	int n;
	int i;
	char gender;
	int man_cnt = 0, woman_cnt = 0;
	int flag = 0;
	//input
	scanf("%d", &n);
	char name_tem[11];
	for (i = 0; i < n; i++)
	{
		getchar();
		scanf("%s", name_tem);
		scanf(" %c", &gender);
		if (gender == 'M')
		{
			strcpy(men[man_cnt].name, name_tem);
			getchar();
			scanf("%s", men[man_cnt].id);
			scanf("%d", &men[man_cnt++].grade);
		}
		else if (gender == 'F')
		{
			strcpy(women[woman_cnt].name, name_tem);
			getchar();
			scanf("%s", women[woman_cnt].id);
			scanf("%d", &women[woman_cnt++].grade);
		}
	}
	int min = 101, max = -1;
	int node_man, node_woman;
	if (woman_cnt != 0)
	{
		for (i = 0; i < woman_cnt; i++)
		{
			if (women[i].grade > max)
			{
				max = women[i].grade;
				node_woman = i;
			}
		}
		printf("%s %s\n", women[node_woman].name, women[node_woman].id);
	}
	else
	{
		flag = 1;
		printf("Absent\n");
	}
	if(man_cnt!=0)
	{
		for (i = 0; i < man_cnt; i++)
		{
			if (men[i].grade < min)
			{
				min = men[i].grade;
				node_man = i;
			}
		}
		printf("%s %s\n", men[node_man].name, men[node_man].id);
	}
	else 
	{
		flag = 1;
		printf("Absent\n");
	}
	if (flag == 1)
	{
		printf("NA\n");
	}
	else
	{
		printf("%d\n", women[node_woman].grade - men[node_man].grade);
	}
	return 0;
}
