#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct stunode
{
	int stu_num;
	char stu_name[5];
	int stu_course[20];
}*Stu;
typedef struct coursenode
{
	int course_num;
	char course_stu[40000][5];
}*Course;
int cmp(const void *a, const void *b)
{
	return strcmp(((struct stunode*)a)->stu_name, ((struct stunode*)b)->stu_name);
}
int main()
{
	int i, j;
	int m, n;
	//input
	scanf("%d %d", &n, &m);
	Stu stu = (Stu)malloc(sizeof(struct stunode)*n);
	Course course = (Course)malloc(sizeof(struct coursenode)*m);
	for (i = 0; i < n; i++)
	{
		getchar();
		scanf("%s", stu[i].stu_name);
		scanf("%d", &stu[i].stu_num);
		for (j = 0; j < stu[i].stu_num; j++)
			scanf("%d", &stu[i].stu_course[j]);
	}
	//process
	qsort(stu, n, sizeof(struct stunode), cmp);
	for (i = 0; i < m; i++)
		course[i].course_num = 0;
	//遍历排好序的学生结构体数组，将每个学生选择的课程记录到课程结构体数组中，课程数组的下标代表这个节点存放的课程号-1
	for (j = 0; j < n; j++)
	{
		for (int k = 0; k < stu[j].stu_num; k++)
			strcpy(course[stu[j].stu_course[k] - 1].course_stu[course[stu[j].stu_course[k] - 1].course_num++], stu[j].stu_name);//
	}
	for(i=0;i<m;i++)
	{
		printf("%d %d\n", i + 1, course[i].course_num);
		for (j = 0; j < course[i].course_num; j++)
			printf("%s\n", course[i].course_stu[j]);
	}
	free(stu);
	free(course);
	return 0;
}
