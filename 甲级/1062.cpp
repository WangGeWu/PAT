#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int id;
	int de;
	int cai;
}man;
//可以使用二维数组保存，输出时更方便
//但是我为什么没改
//懒病得治啊(⊙o⊙)…
man s1[100000];
man s2[100000];
man s3[100000];
man s4[100000];
int cmp(const void *a,const void *b)
{
	if ((((struct node*)a)->de + ((struct node*)a)->cai) != (((struct node*)b)->de + ((struct node*)b)->cai))
	{
		return ((struct node*)b)->de + ((struct node*)b)->cai > ((struct node*)a)->de + ((struct node*)a)->cai;
	}
	else
	{
		if (((struct node*)a)->de != ((struct node*)b)->de)
		{
			return 	((struct node*)b)->de - ((struct node*)a)->de;
		}
		else
		{
			return ((struct node*)a)->id - ((struct node*)b)->id;
		}
	}
}
int main()
{
	int i, j;
	int n, l, h;
	int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
	scanf("%d %d %d", &n, &l, &h);
	int mannum = 0;
	for (i = 0; i < n; i++)
	{
		int x, y,name;
		scanf("%d%d%d",&name, &x, &y);
		if (x >=l&&y >= l)
		{
			mannum++;
			if (x >= h&&y >= h)
			{
				s1[cnt1].id = name; s1[cnt1].de = x; s1[cnt1++].cai = y;
			}
			else if (x >= h&&y < h)
			{
				s2[cnt2].id = name; s2[cnt2].de = x; s2[cnt2++].cai = y;
			}
			else if (x >= y&&x<h&&y<h)
			{
				s3[cnt3].id = name; s3[cnt3].de = x; s3[cnt3++].cai = y;
			}
			else
			{
				s4[cnt4].id = name; s4[cnt4].de = x; s4[cnt4++].cai = y;
			}
		}
	}
	qsort(s1, cnt1, sizeof(struct node), cmp);
	qsort(s2, cnt2, sizeof(struct node), cmp);
	qsort(s3, cnt3, sizeof(struct node), cmp);
	qsort(s4, cnt4, sizeof(struct node), cmp);
	printf("%d\n", mannum);
	for (i = 0; i < cnt1; i++)
	{
		printf("%d %d %d\n", s1[i].id, s1[i].de, s1[i].cai);
	}
	for (i = 0; i < cnt2; i++)
	{
		printf("%d %d %d\n", s2[i].id, s2[i].de, s2[i].cai);
	}
	for (i = 0; i < cnt3; i++)
	{
		printf("%d %d %d\n", s3[i].id, s3[i].de, s3[i].cai);
	}
	for (i = 0; i < cnt4; i++)
	{
		printf("%d %d %d\n", s4[i].id, s4[i].de, s4[i].cai);
	}
	return 0;
}