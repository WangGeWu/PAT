#include<stdio.h>
typedef struct node
{
	int data[1001];
	int front, rear;
}queue;
int FindEarly(queue *service, int n, int m)//查找最早有人离开的窗口，并出队
{
	int i;
	int pos;
	int min = 999999;
	for (i = 0; i < n; i++)
	{
		if (min > service[i].data[service[i].front+1])
		{
			min = service[i].data[service[i].front+1];
			pos = i;
		}
	}
	service[pos].front++;
	return pos;
}
int main()
{
	int time[1001];//保存每个人结束服务的时间
	queue windows[21];
	int queue[1001];//对列
	int head = 0;//队头
	int n, m, k, q; //窗口数量，黄线内允许排队的数量，客户数量，查询次数
	int i, j;
	scanf("%d %d %d %d", &n, &m, &k, &q);
	for (i = 0; i < 21; i++)
	{
		windows[i].front = windows[i].rear = 0;
	}
	for (i = 0; i < k; i++)
		scanf("%d", &queue[i]);
	i = 0; j = 0;
	while (i<m&&head<k)//给窗口排队
	{
		while (j<n)
		{
			if (i == 0)
			{
				windows[j].data[++windows[j].rear] = 8 * 60 + queue[head++];
			}
			else
				windows[j].data[++windows[j].rear] = windows[j].data[windows[j].rear-1] + queue[head++];
			time[head - 1] = windows[j].data[windows[j].rear];
			j++;
		}
		j = 0;
		i++;
	}
	int pos;
	while (head < k)
	{
		pos = FindEarly(windows, n, m);
		windows[pos].data[windows[pos].rear+1]= queue[head++]+windows[pos].data[windows[pos].rear];
		windows[pos].rear++;
		time[head - 1] = windows[pos].data[windows[pos].rear];
	}
	while (q)
	{
		scanf("%d", &i);
		if (time[i - 1] - queue[i - 1] < 17 * 60)
			printf("%02d:%02d\n", time[i - 1] / 60, time[i - 1] % 60);
		else
			printf("Sorry\n");
		q--;
	}
}
