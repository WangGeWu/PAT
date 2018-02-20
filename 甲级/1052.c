#include<stdio.h>
#include<stdlib.h>
struct node {
	int address;
	int num;
	int flag;
	int next;
}list[100001];
int cmp(const void *a, const void *b)
{
	if (((struct node*)a)->flag != ((struct node*)b)->flag)//flag==1的在flag==0的前面
		return ((struct node*)b)->flag - ((struct node*)a)->flag;
	else
		return ((struct node*)a)->num - ((struct node*)b)->num;
}
int main()
{
	int n, head;
	int i;
	scanf("%d %d", &n, &head);
	for (i = 0; i < n; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		list[a].flag = 0;
		list[a].address = a;
		list[a].num = b;
		list[a].next = c;
	}	
	int cnt = 0;
	for (i=head;i != -1; i = list[i].next)//遍历链表，访问过的将flag标记为1
	{
		list[i].flag = 1;
		cnt++;
	}
	if (cnt == 0)
	{
		printf("0 -1");
		return 0;
	}
	qsort(list, 100001, sizeof(struct node), cmp);//排序，将访问过的且值小的排在前面，
	printf("%d %05d\n", cnt, list[0].address);
	for (i = 0; i < cnt; i++)
	{
		if (i != cnt - 1)
			printf("%05d %d %05d\n", list[i].address, list[i].num, list[i+1].address);
		else
		{
			list[i].next = -1;
			printf("%05d %d -1\n", list[i].address, list[i].num);
		}
	}
	return 0;
}
