#include<stdio.h>
#include<malloc.h>
int main()
{
	int K;
	int i, j;
	int start, end;
	int max=0;
	int temp = 0;
	int cnt = 0;
	int *data;
	scanf("%d", &K);
	data = (int*)malloc(K * sizeof(int));
	for (i = 0; i < K; i++)
		scanf("%d", &data[i]);
	start = end = 0;
	for (i = 0; i < K; i++)
	{
		temp = 0;
		if (data[i] < 0)
		{
			cnt++;
			continue;
		}
		for (j = i; j < K; j++)
		{
			temp += data[j];
			if (temp > max)
			{
				start = data[i];
				end = data[j];
				max = temp;
			}
		}
	}
	if (cnt == K)
	{
		printf("0 %d %d", data[0], data[K-1]);
	}
	else 
	printf("%d %d %d", max, start, end);
	return 0;
}
