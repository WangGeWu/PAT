#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct classnode
{
	char stu_name[40000][5];
	int stu_num;
	int id;//索引
};
typedef struct classnode* Pcourse;
struct stunode
{
	char name[5];
	int find_id[50];
	int num;//科目数
};
typedef struct stunode* Pstu;
int cmp(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}
int main()
{
	int i, j,k;
	int n, m;
	//input
	scanf("%d %d", &n, &m);
	Pcourse course = (Pcourse)malloc(sizeof(struct classnode)*m);
	Pstu stu = (Pstu)malloc(sizeof(struct stunode)*n);
	for (i = 0; i < m; i++)
	{
		int findnum, stunum;
		scanf("%d %d", &findnum, &stunum);
		course[i].id = findnum;
		course[i].stu_num = stunum;
		/*
		 *采用malloc分配内存
		 *course[i].stu_name = (char**)malloc(sizeof(char*)*stunum);
		 *for(k=0;k<stunum;k++)
		 *    (course[i].stu_name[k]) = (char*)malloc(sizeof(char) * 5);
		 */
		for (j = 0; j < stunum; j++)
		{
			getchar();
			scanf("%s", course[i].stu_name[j]);
		}
	}
	for (i = 0; i < n; i++)
	{
		getchar();
		scanf("%s", stu[i].name);
	}
	//process
	//find
	int cnt;
	for (i = 0; i < n; i++)
	{
		cnt = 0;
		for (j = 0; j < m; j++)
		{
			for (k = 0; k <course[j].stu_num ; k++)
			{
				if (strcmp(stu[i].name, course[j].stu_name[k])==0)//找到
				{
					stu[i].find_id[cnt++] = course[j].id;
				}
			}
		}
		stu[i].num = cnt;
	}
	//output
	for (i = 0; i < n; i++)
	{
		qsort(stu[i].find_id, stu[i].num, sizeof(int), cmp);
		printf("%s %d", stu[i].name, stu[i].num);
		for (j = 0; j < stu[i].num; j++)
		{
			printf(" %d", stu[i].find_id[j]);	
		}
		printf("\n");
	}
	free(stu);
	free(course);
	return 0;
}