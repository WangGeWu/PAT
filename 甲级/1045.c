#include<stdio.h>
#include<string.h>
/*
  *动态规划
  *类似于LCS
  *v[i][j]表示喜欢颜色的序列的前i个子序列与给出颜色序列的前j个子序列的可求得的最大长度
  *if i==0||j==0:        v[i][j]=0;
  *else if v[i]==v[j]:   v[i][j]=max(v[i-1][j],v[i][j-1])+1
  *else                  v[i][j]=max(v[i-1][j],v[i][j-1])
*/
int v[201][10001];
int love_color[201];
int color[10001];
int Findmax(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	int i, j;
	int n, m,p;
	//input
	scanf("%d %d",&p,&n);
	for (i = 1; i <= n; i++)
		scanf("%d", &love_color[i]);
	scanf("%d", &m);
	for (i = 1; i <= m; i++)
		scanf("%d", &color[i]);
	//process
	for (i = 0; i <= m; i++)
		v[0][i] = 0;
	for (i = 0; i <= n; i++)
		v[i][0] = 0;
	int max = 0;
	for(i=1;i<=n;i++)
		for (j = 1; j <= m; j++)
		{
			if (color[j] != love_color[i])
				v[i][j] = Findmax(v[i][j - 1], v[i - 1][j]);
			else
				v[i][j] = Findmax(v[i][j - 1],v[i - 1][j]) + 1;
			if (v[i][j] > max)
			{
				max = v[i][j];
			}
		}
	printf("%d", max);
}
