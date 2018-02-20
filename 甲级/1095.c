//一个测试点超时
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
	char id[10];
	int time;
	int flag;
}car[10001];
struct tnode
{
	int in_time;
	int out_time;
	char id[10];
	int wait_time;
}tcar[10001];
int cmp2(const void *a, const void *b)
{
	if (((struct tnode*)a)->wait_time != ((struct tnode*)b)->wait_time)
		return ((struct tnode*)a)->wait_time < ((struct tnode*)b)->wait_time;
	else
		return strcmp(((struct tnode*)a)->id, ((struct tnode*)b)->id);
}
int cmp1(const void *a, const void *b)
{
	if (strcmp(((struct node*)a)->id, ((struct node*)b)->id) != 0)
		return strcmp(((struct node*)a)->id, ((struct node*)b)->id);
	else
		return ((struct node*)a)->time - ((struct node*)b)->time;
}
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	int i, j;
	for (i = 0; i < n; i++)
	{
		scanf("%s", car[i].id);
		int h, m, s;
		char str[4];
		scanf("%d:%d:%d", &h, &m, &s);
		car[i].time = h * 3600 + m * 60 + s;
		scanf("%s", str);
		if (str[0] == 'i')
			car[i].flag = 1;
		else
			car[i].flag = -1;
	}
	qsort(car, n, sizeof(struct node), cmp1);
	int cnt = 0;
	for (i = 0; i < n - 1; i++)//将有效的信息保存在另一个数组中
	{
		if (!strcmp(car[i].id, car[i + 1].id) && car[i].flag == 1 && car[i + 1].flag == -1)
		{
			strcpy(tcar[cnt].id, car[i].id);
			tcar[cnt].in_time = car[i].time;
			tcar[cnt].out_time = car[i + 1].time;
			tcar[cnt].wait_time = car[i + 1].time - car[i].time;
			cnt++;
			i++;
		}
	}
	for (i = 0; i < cnt - 1; i++)//计算有效车辆的等待时间
	{
		if (!strcmp(tcar[i].id, tcar[i + 1].id))
		{
			tcar[i + 1].wait_time += tcar[i].wait_time;
			tcar[i].wait_time = 0;
		}
	}
	qsort(tcar, cnt, sizeof(struct tnode), cmp2);
	for (i = 0; i < k; i++)
	{
		int h, m, s;
		scanf("%d:%d:%d", &h, &m, &s);
		int x = h * 3600 + m * 60 + s;
		int y = 0;
		for (j = 0; j < cnt; j++)
		{
			if (x >= tcar[j].in_time&&x < tcar[j].out_time)
				y++;
		}
		printf("%d\n", y);
	}
	printf("%s", tcar[0].id);
	i = 1;
	while (tcar[i].wait_time == tcar[0].wait_time)
	{
		printf(" %s", tcar[i].id);
		i++;
	}
	printf(" %02d:%02d:%02d", tcar[0].wait_time / 3600, tcar[0].wait_time % 3600 / 60, tcar[0].wait_time % 3600 % 60);
	return 0;
}
