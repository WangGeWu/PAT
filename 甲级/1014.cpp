#include<stdio.h>
int FindEarly(int service[][11], int n, int m)//�������������뿪�Ĵ��ڣ����������������ǰ��(����)
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
	int time[1001];//����ÿ���˽��������ʱ��
	int windows[21][11];//ģ�ⴰ��
	int queue[1001];//����
	int head = 0;//��ͷ
	int n, m, k, q; //���������������������Ŷӵ��������ͻ���������ѯ����
	int i, j;
	scanf("%d %d %d %d", &n, &m, &k, &q);
	for (i = 0; i < k; i++)
		scanf("%d", &queue[i]);
	i = 0; j = 0;
	while (i<m&&head<k)//�������Ŷ�
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