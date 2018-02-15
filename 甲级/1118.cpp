#include<stdio.h>
int bird[10001] = {0};
int find(int n)
{
	int x = n;
	while (bird[x] > -1)
		x = bird[x];
	int node = n;
	while (bird[node] > -1)/*路径压缩，否则会超时*/
	{
		int temp = node;
		node = bird[node];
		bird[temp] = x;
	}
		return x;
}
void Union(int n, int m)
{
	int root1 = find(n);
	int root2 = find(m);
	if (root1 != root2) 
	{
		bird[root1] += bird[root2];
		bird[root2] = root1;
	}
}
int main()
{
	int n;
	int i, j;
	scanf ("%d", &n);
	for (i = 0; i < n; i++)
	{
		int m;
		int key1, key2;
		scanf("%d", &m);
		scanf("%d", &key1);
		if (bird[key1] == 0)
			bird[key1] = -1;
		for (j = 1; j < m; j++) {
			scanf("%d", &key2);
			if (bird[key2] == 0)
				bird[key2] = -1;
			Union(key1, key2);
		}
	}
	int cnt = 0;
	int num = 0;
	for (i = 1; i < 10001; i++)
	{
		if (bird[i] < 0)
		{
			cnt++;
			num += bird[i];
		}
	}
	printf("%d %d\n", cnt,-num);
	int k;
	scanf("%d", &k);
	for (i = 0; i < k; i++)
	{
		int v1, v2;
		scanf("%d%d", &v1, &v2);
		if (find(v1) == find(v2))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}