#include<stdio.h>
int post[31];
int mid[31];
int flag[1001];
void change(int start, int end, int root,int indix)
{
	if (start > end)return;
	int i = start;
	while (i < end&&mid[i] != post[root])i++;
		flag[indix] = post[root];
	change(start, i - 1, root - (end - i + 1),2*indix+1);
	change(i + 1, end, root - 1,2*indix+2);
}
int main()
{
	int node, i;
	scanf("%d", &node);
	for (i = 0; i < 1001; i++)
		flag[i] = -1;
	for (i = 0; i < node; i++)
	{
		scanf("%d", &post[i]);
	}
	for (i = 0; i < node; i++)
	{
		scanf("%d", &mid[i]);
	}
	change(0, node - 1, node - 1,0);
	int cnt = 0;
	for (i = 0; i < 1001; i++)
	{
		if (flag[i] != -1)
		{
			if (i == 0)printf("%d", flag[i]);
			else 
			printf(" %d", flag[i]);
			cnt++;
		}
		if (cnt == node)break;
	}
	return 0;
}