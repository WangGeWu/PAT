#include<stdio.h>
int graph[210][210];
int flag[210];
int n;
int judge(int a[], int x)
{
	
	int i;
	if (n + 1 != x)return 0;//�������
	if (a[0] != a[x - 1])return 0;//��β�Ƿ����
	for (i = 0; i < x - 1; i++)//���ڶ����Ƿ��б�
		if (graph[a[i]][a[i + 1]] == 0)
			return 0;
	for (i = 1; i < x - 1; i++)//����β��û���ظ��ڵ�
	{
		flag[a[i]]++;
		if (flag[a[i]] == 2||a[i]==a[0])//�м����в��ܳ�����β�ڵ�
			return 0;
	}
	return 1;
}
int main()
{
	int m;
	scanf("%d%d", &n, &m);
	int i, j;
	for (i = 0; i < m; i++)
	{
		int v1, v2;
		scanf("%d%d", &v1, &v2);
		graph[v1][v2] = graph[v2][v1] = 1;
	}
	int k;
	int v[1000];
	scanf("%d", &k);
	int x;
	for (i = 0; i < k; i++)
	{
		for (int p = 0; p < 210; p++)
			flag[p] = 0;
		scanf("%d", &x);
		for (j = 0; j < x; j++)
			scanf("%d", &v[j]);
		if (judge(v, x))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}