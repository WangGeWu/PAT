#include<stdio.h>
#include<stdlib.h>
struct MyStruct
{
	int ID;
	int score[4];
	int rank[4];
	char Max;
	int s;
}v[2048];
int k = 0;
int cmp(const void *a, const void *b)
{
	return (((const struct MyStruct*)a)->score[k] >((const struct MyStruct*)b)->score[k]);
}
int main()
{
	char a[4] = { 'A','C','M','E' };
	int num, M;
	int i;
	int name;
	printf("!!");
	scanf("%d%d", &num, &M);
	for (i = 0; i < num; i++)//³õÊ¼»¯
	{
		scanf("%d%d%d%d", &v[i].ID, &v[i].score[1], &v[i].score[2], &v[i].score[3]);
		v[i].score[0] = (v[i].score[1] + v[i].score[2] + v[i].score[3]) / 3;
	}
	while (k<4)
	{
		qsort(v, num, sizeof(struct MyStruct), cmp);
		v[0].rank[k] = 1;
		for (i = 1; i < num; i++)
		{
			if (v[i].score[0] == v[i - 1].score[0])
				v[i].rank[k] = v[i - 1].rank[k];
			else
				v[i].rank[k] = i + 1;
		}
		k++;
	}
	int min = 10;
	int j, temp;
	for (i = 0; i<num; i++)
	{
		id[v[i].ID] = i;
		for (j = 0; j < 4; j++)
		{
			if (min > v[i].rank[j])
			{
				min = v[i].rank[j];
				temp = j;
			}
		}
		v[i].Max = a[j]; v[i].s = min;
	}
	while (M)
	{
		scanf("%d", &name);
		if (id[name] == -1)
			printf("N\A");
		else
			printf("%d %c", v[id[name]].s, v[id[name]].Max);
		M--;
	}
	return 0;
}
int cmp(struct MyStruct *a, struct MyStruct *b)
{
	return (a->score[k] > b->score[k]);
}