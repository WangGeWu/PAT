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
void Exchange(int start, int end, int root)//start、end为要处理数组的起始截止下标，root为层序遍历根节点所在下标
{
	if (end < start)
		return;
	int n = end - start + 1;
	int h = log(n + 1) / log(2);//树高
	int level = min(pow(2, h - 1), n - pow(2, h)+1);//最底层的节点数
	int a_root = start + level + (pow(2, h)-2)/2;//中序遍历序列的树根节点下标
	b[root] = a[a_root];
	Exchange(start, a_root - 1, 2 * root + 1);//递归左子树
	Exchange(a_root + 1, end, 2 * root + 2);//递归右子树
}
int main()
{
	int n;
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	qsort(a, n, sizeof(int), cmp);//将节点排序后的序列为中序遍历的序列，因此递归解决根，左子树，右子树
	Exchange(0,n-1,0);
	printf("%d", b[0]);
	for (i = 1; i < n; i++)
		printf(" %d", b[i]);
	return 0;
}
