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
	int flag=0;
	int *data;
	scanf("%d", &K);
	data = (int*)malloc(K * sizeof(int));
	for (i = 0; i < K; i++)
		scanf("%d", &data[i]);
	start = 0; end = K - 1;
	max = -1;//很关建的初始化啊，因为序列值为0时，也需要更新start和end的值
	for (i = 0; i < K; i++)
	{
		temp += data[i];
		if (temp > max)
		{
			max = temp;
			end = i;
			start = flag;
		}
		else if (temp < 0)
		{
			temp = 0;
			flag = i + 1;
		}
	}
	for (i = 0; i < K; i++)
	{
		if (data[i] < 0)
			cnt++;
	}
	if (cnt == K)
	{
		printf("0 %d %d", data[start], data[end]);
	}
	else 
	printf("%d %d %d", max, data[start], data[end]);
	return 0;
}
