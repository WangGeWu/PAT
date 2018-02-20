//两个测试点超时，可以采用hash的思想,硬币的价值对应数组下标存放，数组内容存放次价值的硬币数量
//但是为什么不改呢，因为我懒啊
#include<stdio.h>
int coin[100001];
int main()
{
	int v1, v2;
	int low, high;
	int n, m;
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%d", &coin[i]);
	int flag = 0;
	int min = 1001;
	for (i = 0; i<n; i++)
		for (j = i + 1; j < n; j++)
		{
			if (coin[i] + coin[j] == m)
			{
				flag = 1;
				if (coin[i] < coin[j])
				{
					low = i;
					high = j;
				}
				else
				{
					low = j;
					high = i;
				}
				if (coin[low] < min)
				{
					min = coin[low];
					v1 = low;
					v2 = high;
				}
			}
		}
	if (flag == 1)
		printf("%d %d", coin[v1], coin[v2]);
	else
		printf("No Solution");
	return 0;
}
