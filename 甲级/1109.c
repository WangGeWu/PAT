#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	int height;
	char name[9];
}man[10001];
int line_num[11];
char queue[11][1001][9];
int cmp(const void*a, const void*b)
{
	if (((struct node*)b)->height != ((struct node*)a)->height)
		return ((struct node*)b)->height - ((struct node*)a)->height;
	else
		return strcmp(((struct node*)a)->name, ((struct node*)b)->name);
}
int main()
{
	int i, j;
	int n, k;
	scanf("%d%d", &n,&k);
	for (i = 0; i < n; i++)
	{
		scanf("%s%d", &man[i].name, &man[i].height);
	}
	int num = n / k;
	int last_num=n-(k-1)*num;
	for (i = 1; i < k; i++)
		line_num[i] = num;
	line_num[0] = last_num;
	qsort(man, n, sizeof(struct node), cmp);
	int cnt = 0;
	for (i = 0; i < k; i++)
	{
		int mid = line_num[i] / 2;
		for (j = 0; j <= mid; j++)
		{
			if (j == 0)
				strcpy(queue[i][mid - j], man[cnt++].name);
			else {
				if (mid - j >= 0)
					strcpy(queue[i][mid - j], man[cnt++].name);
				if (mid + j < line_num[i])
					strcpy(queue[i][mid + j], man[cnt++].name);
			}
		}
		for (int p = 0; p < line_num[i]; p++)
		{
			printf("%s", queue[i][p]);
			if (p != line_num[i] - 1)
				printf(" ");
			else
				printf("\n");
		}
	}
	return 0;
}
