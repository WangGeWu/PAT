//�������Ե㳬ʱ�����Բ���hash��˼��,Ӳ�ҵļ�ֵ��Ӧ�����±��ţ��������ݴ�Ŵμ�ֵ��Ӳ������
//����Ϊʲô�����أ���Ϊ������
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