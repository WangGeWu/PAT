#include<stdio.h>
int num[100000];
int pos[100000];
int main()
{
	int cnt = 0;
	int i;
	int n;
	int node;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
		pos[num[i]] = i;//��¼num[i]�洢��λ��,����ᳬʱ
	}
	int flag;
	int index=0;
	node = pos[0];//node��¼0�����±�
	while (1)
	{
		if (node == 0)//���0���±�0��������0�͵�һ��������λ�õ���
		{
			flag = 0;
			for (i = index; i < n; i++)
			{
				if (num[i] != i)
				{
					flag = 1;
					index = i;//index�洢��һ��������λ�õ������±�,��һ��ѭ��ʱ����index��ʼѭ��
					break;
				}
			}
			if (flag == 0)break;
			num[node] = num[i];//����
			pos[num[i]] = node;//����pos
			num[i] = 0;//����
			pos[0] = i;//����pos
			node = i;//����node
			cnt++;
		}
		else
	    {
			num[pos[node]] = 0;
			pos[0] = pos[node];
			num[node] = node;
			pos[node] = node;
			node = pos[0];
			cnt++;
		}
    }
	printf("%d", cnt);
	return 0;
}