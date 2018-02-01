#include<stdio.h>
int dist[100001];
int num[100001];
int Findmin(int a, int b)
{
	return a < b ? a : b;
}
int main()
{
	int i,j;
	int add = 0;
	int n, m;
	scanf("%d", &n);
	dist[0] = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
		dist[i+1]=dist[i]+num[i];
		add += num[i];
	}
		scanf("%d", &m);
	int cnt1,cnt2;
	for (j = 0; j < m; j++)
	{
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		v1--; v2--;
		cnt1 = dist[v2]-dist[v1];
		if (cnt1 < 0)
			cnt1 = -cnt1;
		cnt2 = add - cnt1;
		printf("%d\n",Findmin(cnt1, cnt2));
	}
	return 0;
}