#include<stdio.h>
int color[600][800];
int num[16777216];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int i, j;
	int x = m*n / 2;
	for(i=0;i<m;i++)
		for (j = 0; j < n; j++)
		{
			scanf("%d", &color[i][j]);
			num[color[i][j]]++;
			if (num[color[i][j]] > x)
			{
				printf("%d", color[i][j]);
				return 0;
			}
		}
}