#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int a[10001];
int b[500][500];
int cmp(const void*a, const void*b)
{
	return *(int*)b - *(int*)a;
}
int main()
{
	int n;
	int i, j, k, p;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int m = sqrt(n);
	for (i = m; i > 0; i--)
	{
		if (n%i == 0)
			break;
	}
	qsort(a, n, sizeof(int), cmp);
	int temp = n;
	m = n / i; n = i;//m*n
	int cnt = 0;
	int x, y;//x横坐标，y纵坐标
	int top = 0, bottom = m - 1, left = 0, right = n - 1;//分别表示矩阵的上下左右边界
	int flag = 0;
	while (1)
	{
		x = top;
		for (y = left; y <= right; y++)//right
		{
			b[x][y] = a[cnt++];
			if (cnt == temp)//数据处理完后，跳出循环
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			break;
		y--;
		for (x = x + 1; x <= bottom; x++)//bottom
		{
			b[x][y] = a[cnt++];
			if (cnt == temp)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			break;
		x--;
		for (y = y - 1; y >= left; y--)//left
		{
			b[x][y] = a[cnt++];
			if (cnt == temp)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			break;
		y++;
		for (x = x - 1; x > top; x--)//top
		{
			b[x][y] = a[cnt++];
			if (cnt == temp)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			break;
		top = top + 1;
		bottom = bottom - 1;
		left = left + 1;
		right = right - 1;
	}
	for(i=0;i<m;i++)
		for (j = 0; j < n; j++)
		{
			printf("%d", b[i][j]);
			if (j == n - 1)
				printf("\n");
			else
				printf(" ");
		}
	return 0;
}