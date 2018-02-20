#include<stdio.h>
#include<stdlib.h>
struct node
{
	int start;
	int end;
}S[10001];
int FindMin(int a[],int n)
{
	int min = 99999;
	int pos;
	for (int i = 0; i < n; i++)
	{
		if (min > a[i])
		{
			min = a[i];
			pos = i;
		}
	}
	return pos;
}
int cmp(const void* a, const void* b)
{
	return((struct node*)a)->start - ((struct node*)b)->start;

}
int main()
{
	int n,k;//客户总数，窗口数量
	int window[101];//模拟窗口
	int i, j;
	int num=0;//记录有效的用户数量
	int s;
	int hh, mm, ss, time;
	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++)
	{
		scanf("%d:%d:%d %d", &hh, &mm, &ss, &time);
		s = hh * 60 * 60 + mm * 60 + ss;
		if (time > 60)
			time = 60;
		if (s <= 17 * 60 * 60)//记录17点之前到的用户
		{
			S[num].start = s;
			S[num++].end = s + time * 60;
		}
	}
	qsort(S, num, sizeof(struct node), cmp);//按到来时间顺序排队
	for (i = 0; i < k; i++)//初始化窗口的时间（8点）
	{
		window[i] = 8 * 60 * 60;
	}
	int cnt = 0;
	int pos;
	double wait_time=0.0;
	while (cnt < num)
	{
		pos = FindMin(window, k);//查找最早结束的窗口
		int w=S[cnt].end - S[cnt].start;
		if (S[cnt].start < window[pos])
		{
			wait_time += window[pos] - S[cnt].start;
			window[pos] += w;
		}
		else
		{
			window[pos] = S[cnt].end;
		}
        cnt++;
	}
	printf("%.1lf\n", wait_time / (num * 60));
}
