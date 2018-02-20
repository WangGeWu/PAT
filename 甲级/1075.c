#include<stdio.h>
#include<stdlib.h>
struct node
{
	int id;
	int rank;
	int score[5] = {-2,-2,-2,-2,-2};
	int visit=0;
	int add_score=0;
	int num=0;
}stu[100000];
int cmp(const void *a,const void*b)
{
	if (((struct node*)a)->visit != ((struct node*)b)->visit)
		return ((struct node*)a)->visit < ((struct node*)b)->visit;
	else
	{
		if (((struct node*)a)->add_score != ((struct node*)b)->add_score)
		{
			return ((struct node*)a)->add_score < ((struct node*)b)->add_score;
		}
		else
		{
			if (((struct node*)a)->num != ((struct node*)b)->num)
				return ((struct node*)a)->num < ((struct node*)b)->num;
			else
				return ((struct node*)a)->id > ((struct node*)b)->id;
		}
	}
}
int main()
{
	int i, j;
	int s[10];
	int n, k, m;
	scanf("%d%d%d", &n, &k, &m);
	for (i = 0; i < k; i++)
		scanf("%d", &s[i]);
	for (i = 0; i < m; i++)
	{
		int id,x,y;
		scanf("%d%d%d", &id,&x,&y);
		id--;
		stu[id].id = id+1;
		if (y > stu[id].score[x-1])
		{
			if (y != -1)
			{
				if (y == s[x - 1])
					stu[id].num++;//Âú·ÖµÄ¿ÆÄ¿Êý
				stu[id].visit = 1;
				stu[id].score[x - 1] = y;
			}
			else
			{
				stu[id].score[x - 1] = 0;
			}
		}
	}
	int cnt = 0;
	for (i = 0; i < n; i++)
	{
		if (stu[i].visit == 1)
		{
			cnt++;
			for (j = 0; j < k; j++)
				if(stu[i].score[j]!=-2)
				stu[i].add_score += stu[i].score[j];
		}
	}
	qsort(stu, n,sizeof(struct node), cmp);
	for (i = 0; i < cnt; i++)
	{
		if (i == 0)
		{
			stu[i].rank = 1;
			printf("%d %05d %d",stu[i].rank,stu[i].id,stu[i].add_score);
		}
		else
		{
			if (stu[i].add_score == stu[i - 1].add_score)
			{
				stu[i].rank = stu[i - 1].rank;
				printf("%d %05d %d", stu[i].rank, stu[i].id, stu[i].add_score);
			}
			else
			{
				stu[i].rank = i+1;
				printf("%d %05d %d", stu[i].rank, stu[i].id,stu[i].add_score);
			}
		}
		for (j = 0; j < k; j++)
			if (stu[i].score[j] != -2)
				printf(" %d", stu[i].score[j]);
			else
				printf(" -");
		printf("\n");
	}
	return 0;
}
