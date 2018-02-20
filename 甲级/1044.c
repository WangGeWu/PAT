//两个测试点超时
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int start;
	long num;
	int end;
}list[100001];
int cmp(const void *a, const void *b)
{
	if ((((struct node*)a)->num - ((struct node*)b)->num) != 0)
		return ((struct node*)a)->num - ((struct node*)b)->num;
	else return ((struct node*)a)->start - ((struct node*)b)->start;
}
int main()
{
	int *a;
	int n;
	long m;
	int i, j;
	//input
	scanf("%d %ld", &n, &m);
	a = (int*)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	//process
	//最长公共子序列算法的修改
	long min=100000001;
	int value;
	int cnt=0;
	for (i = 0; i < n; i++)
	{
		value = 0;
		for (j = i; j < n; j++)
		{
			value += a[j];
			if (value >= m&&value <= min)
			{			
				min = value;
				list[cnt].start = i + 1;
				list[cnt].end = j + 1;
				list[cnt++].num = value;
				break;
			}
			else if (value > min)
			{
				break;
			}
		}
	}
	qsort(list, cnt, sizeof(struct node), cmp);
	i = 0;
	//output
	while (list[i].num == list[0].num)
	{
		printf("%d-%d\n", list[i].start, list[i].end);
		i++;
	}
	free(a);
	return 0;
}
