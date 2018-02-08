#include<stdio.h>
int front[31];//先序
int mid[31];//中序
int post[31];//后序
void ToPost(int f,int m,int p,int n)//f为前序数组的首元素下标，m为中序数组首元素的下标，p为后序数组首元素的下标
{
	if (n <= 0)                         
		return;
	int i=m;
	while (mid[i] != front[f])i++;
	int l1 = i - m, l2 = n - i + m - 1;
	post[p + n - 1] = front[f];
	ToPost(f+1,m,p,l1);//递归左子树
	ToPost(f+1+l1,i+1,p+l1,l2);//递归右子树
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
			front[cnt1] = num;//先序遍历数组
			stack[++top] = num;
			cnt1++;//push出现的次数加一
		}
		else
		{
			mid[cnt2] = stack[top--];//中序遍历数组
			cnt2++;//pop出现的次数加一
		}
	}
	ToPost(0,0,0,n);
	printf("%d", post[0]);
	for (i = 1; i < n; i++)
		printf(" %d", post[i]);
	return 0;
}