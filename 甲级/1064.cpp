#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int a[1000];
int b[1000];
int min(int a, int b)
{
	return a < b ? a : b;
}
int cmp(const void*a, const void *b)
{
	return *(int*)a > *(int*)b;
}
void Exchange(int start, int end, int root)//start��endΪҪ�����������ʼ��ֹ�±꣬rootΪ����������ڵ������±�
{
	if (end < start)
		return;
	int n = end - start + 1;
	int h = log(n + 1) / log(2);//����
	int level = min(pow(2, h - 1), n - pow(2, h)+1);//��ײ�Ľڵ���
	int a_root = start + level + (pow(2, h)-2)/2;//����������е������ڵ��±�
	b[root] = a[a_root];
	Exchange(start, a_root - 1, 2 * root + 1);//�ݹ�������
	Exchange(a_root + 1, end, 2 * root + 2);//�ݹ�������
}
int main()
{
	int n;
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	qsort(a, n, sizeof(int), cmp);//���ڵ�����������Ϊ������������У���˵ݹ���������������������
	Exchange(0,n-1,0);
	printf("%d", b[0]);
	for (i = 1; i < n; i++)
		printf(" %d", b[i]);
	return 0;
}