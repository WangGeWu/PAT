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
	int n,k;//�ͻ���������������
	int window[101];//ģ�ⴰ��
	int i, j;
	int num=0;//��¼��Ч���û�����
	int s;
	int hh, mm, ss, time;
	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++)
	{
		scanf("%d:%d:%d %d", &hh, &mm, &ss, &time);
		s = hh * 60 * 60 + mm * 60 + ss;
		if (time > 60)
			time = 60;
		if (s <= 17 * 60 * 60)//��¼17��֮ǰ�����û�
		{
			S[num].start = s;
			S[num++].end = s + time * 60;
		}
	}
	qsort(S, num, sizeof(struct node), cmp);//������ʱ��˳���Ŷ�
	for (i = 0; i < k; i++)//��ʼ�����ڵ�ʱ�䣨8�㣩
	{
		window[i] = 8 * 60 * 60;
	}
	int cnt = 0;
	int pos;
	double wait_time=0.0;
	while (cnt < num)
	{
		pos = FindMin(window, k);//������������Ĵ���
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