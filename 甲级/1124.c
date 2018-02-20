#include<stdio.h>
#include<string.h>
struct node
{
	int flag;
	char name[21];
}people[1001];
struct fnode//存放获奖的转发
{
	char name[21];
}fpeo[1001];
int judge(char *s,int n)/*判断转发是否已经出现过*/
{
    for (int i = 0; i < n; i++)
		if (!strcmp(s, fpeo[i].name))
	   		return 0;
	return 1;
}
int main()
{
	int i, j;
	int m, n, s;
	scanf("%d%d%d", &m, &n, &s);
	for (i = 1; i <= m; i++)
	{
		scanf("%s", people[i].name);
	}
	j = s;
	if (j > m)
		printf("Keep going...\n");
	else 
	{
		int cnt = 0;
		while (j <= m)
		{
			if (judge(people[j].name, cnt))
			{
				printf("%s\n", people[j].name);
				strcpy(fpeo[cnt++].name, people[j].name);
				j += n;
			}
			else
				j++;
		}
	}
	return 0;
}
