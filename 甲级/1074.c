#include<stdio.h>
#include<stdlib.h>
struct node {
	int key;
	int next;
}list[100000];
int a[100000];
int main()
{
	int i;
	int head, n, k;
	scanf("%d%d%d", &head, &n, &k);
	for (i = 0; i < n; i++)
	{
		int add;
		scanf("%d", &add);
		scanf("%d%d", &list[add].key, &list[add].next);
	}
	int cnt = 0;
	for (i = head; list[i].next != -1; i = list[i].next)
	{
		a[cnt++] = i;
	}
	a[cnt++] = i;
	int x = cnt%k;
	int y = cnt / k;
	int j = 0;
	while (j<y)
	{
		for (i = 0; i <= (k-1)/2; i++)
		{
			int temp=a[j*k+i];
			a[j*k + i] = a[j*k + k - i-1];
			a[j*k + k - i-1] = temp;
		}
		j++;
	}
	for (i = 0; i < cnt-1; i++)
	{
		printf("%05d %d %05d\n", a[i], list[a[i]].key, a[i + 1]);
	}
	printf("%05d %d -1", a[i], list[a[i]].key);
	return 0;
}
