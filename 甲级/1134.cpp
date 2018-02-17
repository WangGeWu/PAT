#include<stdio.h>
int a[10000], b[10000],c[10000];
int hash[100][10000];
int main()
{
	int m, n;
	int cnt1 = 0, cnt2 = 0;
	scanf("%d%d", &n, &m);
	int i, j;
	for (i = 0; i < m; i++)
	{
		int v1, v2;
		scanf("%d%d", &v1, &v2);
		a[cnt1++] = v1;
		b[cnt2++] = v2;
	}
	int k;
	scanf("%d", &k);
	int flag;
	for (i = 0; i < k; i++)
	{
		flag = 1;
		int x;
		scanf("%d", &x);
		for (j = 0; j < x; j++)
		{
			scanf("%d", &c[j]);
			hash[i][c[j]] = 1;
		}
		for (j = 0; j < cnt1; j++)
		{
			if (hash[i][a[j]] != 1 && hash[i][b[j]] != 1)
			{
				printf("No\n");
				flag = 0;
				break;
			}
		}
		if (flag == 1)printf("Yes\n");
	}
	return 0;
}