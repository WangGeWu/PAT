#include<stdio.h>
#include<stdlib.h>
int flag[201][1001];
int judge(int a[], int n,int m)
{
	for (int i = 0; i < n; i++)
	{
		if (flag[m][a[i]] == 1)
			return 0;
		else
			flag[m][a[i]] = 1;
		for (int j = i + 1; j < n; j++)
		{
			if (abs(a[j] - a[i]) == (j - i))
				return 0;
		}
	}
	return 1;
}
int main()
{
	int a[1001];
	int k;
	scanf("%d", &k);
	int i, j;
	for (i = 0; i < k; i++)
	{
		int n;
		scanf("%d", &n);
		for (j = 0; j < n; j++)
		{
			scanf("%d", &a[j]);
		}
		judge(a, n,i) ? printf("YES\n") : printf("NO\n");
	}
	return 0;
}