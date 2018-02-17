#include<stdio.h>
struct node
{
	int key;
	int next;
}list[1000000];
struct anode
{
	int key;
	int address;
}list_a[100000];
struct bnode
{
	int key;
	int address;
}list_b[100000];
struct cnode
{
	int key;
	int address;
}list_c[100000];
int main()
{
	int head,n, k;
	int i;
	int cnt_a = 0, cnt_b = 0, cnt_c = 0;
	scanf("%d%d%d", &head, &n, &k);
	for (i = 0; i < n; i++)
	{
		int address;
		scanf("%d", &address);
		scanf("%d%d", &list[address].key, &list[address].next);
	}
	i = head;
	do 
	{
		if (list[i].key < 0)
		{
			list_a[cnt_a].key = list[i].key;
			list_a[cnt_a++].address = i;
		}
		else if (list[i].key > k)
		{
			list_c[cnt_c].key = list[i].key;
			list_c[cnt_c++].address = i;
		}
		else
		{
			list_b[cnt_b].key = list[i].key;
			list_b[cnt_b++].address = i;
		}
		i = list[i].next;
	}while (i != -1);
	int cnt = 0;
	//将三个数组拷贝到结果数组中去
	for (i = 0; i < cnt_a; i++)
	{
		list[cnt].key = list_a[i].key;
		list[cnt++].next = list_a[i].address;//next 保存元素当前地址，减少内存的使用
	}
	for (i = 0; i < cnt_b; i++)
	{
		list[cnt].key = list_b[i].key;
		list[cnt++].next = list_b[i].address;
	}
	
	for (i = 0; i < cnt_c; i++)
	{
		list[cnt].key = list_c[i].key;
		list[cnt++].next = list_c[i].address;
	}
	for (i = 0; i < cnt; i++)
	{
		if (i != cnt - 1)
			printf("%05d %d %05d\n", list[i].next, list[i].key, list[i + 1].next);
		else
			printf("%05d %d -1", list[i].next, list[i].key);
	}
	return 0;
}
