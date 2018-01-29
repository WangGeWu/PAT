#include<stdio.h>
int FindEarly(int service[][11], int n, int m)//查找最早有人离开的窗口，并将后面的人依次前移(出队)
{
	int i;
	int pos;
	int min = 999999;
	for (i = 0; i < n; i++)
	{
		if (min > service[i][0])
		{
			min = service[i][0];
			pos = i;
		}
	}
	for (i = 0; i < m - 1; i++)
		service[pos][i] = service[pos][i + 1];
	return pos;
}
int main()
{
	int time[1001];//保存每个人结束服务的时间
	int windows[21][11];//模拟窗口
	int queue[1001];//对列
	int head = 0;//队头
	int n, m, k, q; //窗口数量，黄线内允许排队的数量，客户数量，查询次数
	int i, j;
	scanf("%d %d %d %d", &n, &m, &k, &q);
	for (i = 0; i < k; i++)
		scanf("%d", &queue[i]);
	i = 0; j = 0;
	while (i<m&&head<k)//给窗口排队
	{
		while (j<n)
		{
			if (i == 0)
				windows[j][i] = 8*60+queue[head++];
			else
				windows[j][i] = windows[j][i - 1] + queue[head++];
			time[head - 1] = windows[j][i];
			j++;
		}
		j = 0;
		i++;
	}
	int pos;
	while (head < k)
	{
		pos = FindEarly(windows, n, m);
		windows[pos][m - 1] += queue[head++];
		time[head - 1] = windows[pos][m - 1];
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