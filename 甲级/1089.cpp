//´ıÍêÉÆ
#include<stdio.h>
#include<stdlib.h>
int n1[100], n2[100];
int n;
int cmp(const void *a, const void *b)
{
	return *(int*)a > *(int*)b;
}
void marge(int start, int end)
{
	int i;
	if (end <= start)
		return;
	int mid = (start + end) / 2;
	marge(start, mid);
	marge(mid + 1, end);
	qsort(n1 + start, end - start + 1, sizeof(int), cmp);
}
int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &n1[i]);
	for (i = 0; i < n; i++)
		scanf("%d", &n2[i]);
	for (i = 0; i < n-1&&n2[i] < n2[i + 1]; i++);
	for(j = i + 1; j < n&&n2[j] == n1[j];j++);
	if (j == n)
	{
		printf("Insertion Sort\n");
		qsort(n2, i+2, sizeof(int), cmp);
		for (i = 0; i < n; i++)
			printf(" %d", n2[i]);
	}
	else
	{
		printf("Merge Sort\n");
		marge(0, n - 1);
		for (i = 0; i < n; i++)
			printf(" %d", n1[i]);
	}
}