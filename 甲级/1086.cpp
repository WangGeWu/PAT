#include<stdio.h>
int front[31];//����
int mid[31];//����
int post[31];//����
void ToPost(int f,int m,int p,int n)//fΪǰ���������Ԫ���±꣬mΪ����������Ԫ�ص��±꣬pΪ����������Ԫ�ص��±�
{
	if (n <= 0)                         
		return;
	int i=m;
	while (mid[i] != front[f])i++;
	int l1 = i - m, l2 = n - i + m - 1;
	post[p + n - 1] = front[f];
	ToPost(f+1,m,p,l1);//�ݹ�������
	ToPost(f+1+l1,i+1,p+l1,l2);//�ݹ�������
}
int main()
{
	int stack[100];
	int top = -1;
	int n, i;
	scanf("%d", &n);
	int cnt1=0, cnt2 = 0;
	//input
	while (cnt1 < n||cnt2 < n)
	{
		char s[5];
		int num;
		scanf("%s", s);
		if (s[1] == 'u')
		{
			scanf("%d", &num);
			front[cnt1] = num;//�����������
			stack[++top] = num;
			cnt1++;//push���ֵĴ�����һ
		}
		else
		{
			mid[cnt2] = stack[top--];//�����������
			cnt2++;//pop���ֵĴ�����һ
		}
	}
	ToPost(0,0,0,n);
	printf("%d", post[0]);
	for (i = 1; i < n; i++)
		printf(" %d", post[i]);
	return 0;
}