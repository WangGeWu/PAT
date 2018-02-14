#include<stdio.h>
#include<stdlib.h>
struct stunode
{
	int find_id[50];
	int num;//科目数
}stu[175850];
int cmp(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}
int main()
{
	int i, j, k;
	int n, m;
	//input
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++)
	{
		int findnum, stunum;
		scanf("%d %d", &findnum, &stunum);
		for (j = 0; j < stunum; j++)
		{
			char id[5];
			scanf("%s",id);
			int v = ((id[0] - 'A') * 26 * 26 + (id[1] - 'A') * 26 + id[2] - 'A')*10 + id[3] - '0';
			stu[v].find_id[stu[v].num++] = findnum;
		}
	}
	//find
	for (i = 0; i < n; i++)
	{
		char s[5];
		scanf("%s", s);
		int v = ((s[0] - 'A') * 26 * 26 + (s[1] - 'A') * 26 + s[2] - 'A')*10 + s[3] - '0';
		qsort(stu[v].find_id,stu[v].num,sizeof(int),cmp);
		printf("%s %d", s, stu[v].num);
		for (j = 0; j < stu[v].num; j++)
		{
			printf(" %d", stu[v].find_id[j]);
		}
		printf("\n");
	}
	//output
	return 0;
}
