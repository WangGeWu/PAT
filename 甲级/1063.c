//一个点超时
//很蛋疼啊，用hash时内存超了，不hash了，时间又超了
#include<stdio.h>
int integer[50][10000];
int num[50];
int find(int *a,int key,int n)
{
	for (int i = 0; i < n; i++)
		if (a[i] == key)
			return 1;
	return 0;
}
int main()
{
	int i, j;
	int n, m, k;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &m);
		int cnt = 0;
		for (j = 0; j < m; j++)
		{
			int x;
			scanf("%d", &x);
            if(!find(integer[i],x,cnt))
			{
				integer[i][cnt++] = x;
			}
		}
		num[i] = cnt;
	}
	int nc, nt;
	int flag;
	scanf("%d", &k);
	for (i = 0; i < k; i++)
	{
		int s1, s2;
		scanf("%d%d", &s1, &s2);
		s1--; s2--;
		nc = 0; nt = num[s2];
		for (j = 0; j<num[s1]; j++)
		{
			if (find(integer[s2], integer[s1][j],num[s2]))
				nc++;
			else
				nt++;
		}
		printf("%.1f%%\n", (double)nc / nt * 100);
	}
	return 0;
}
