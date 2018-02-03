#include<stdio.h>
//以320位基数，将原数hash
int stack[320 * 320];
int count[320];
int table[320][320];
int top = -1;
void Push(int key)
{
	stack[++top] = key;
	count[key / 320]++;
	table[key / 320][key % 320]++;
}
void Pop()
{
	if (top == -1)
		printf("Invalid\n");
	else
	{
		count[stack[top] / 320]--;
		table[stack[top] / 320][stack[top] % 320]--;
     	printf("%d\n", stack[top--]);
	}
}
void PeekMedian()
{
	if (top == -1)
		printf("Invalid\n");
	else
	{
		int i, j;
		int k = (top + 1 + 1) / 2, cnt = 0;
		for (i = 0; i < 320; i++)//计算以320位基数的十位从0到i的数量
		{
			if (cnt+count[i] >= k)
			{
				break;
			}
			else
				cnt += count[i];
		}
		for (j = 0; j < 320; j++)
		{
			cnt += table[i][j];
			if (cnt>= k)
			{
				printf("%d\n", i * 320 + j);
				break;
			}
		}
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	char s[11];
	for (int i = 0; i < n; i++) 
	{
		scanf("%s", s);
		switch (s[1])
		{
		case 'o':Pop(); break;
		case 'u': {int key; scanf("%d", &key); Push(key); } break;
		case 'e':PeekMedian(); break;
		}
	}
	return 0;

}