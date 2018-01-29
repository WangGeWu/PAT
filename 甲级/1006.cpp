#include<stdio.h>
#include<stdlib.h>
#define Max 100
typedef struct ENode
{
	int end;
	int position;
}End[Max];
typedef struct SNode
{
	int start;
	int position;
}Start[Max];
int compareEnode(const void *a, const void *b)
{ 
	return (((const struct ENode*)a)->end - ((const struct ENode*)b)->end);
}
int compareSnode(const void *a, const void *b)
{
	return (((const struct SNode*)a)->start - ((const struct SNode*)b)->start);
}
int main()
{
	int M;
	Start start;
	End end;
	char ID[Max][16];
	int h, m, s;
	int i;
	scanf("%d", &M);
	for (i = 0; i < M; i++)
	{
		scanf("%s", ID[i]);
		scanf("%d:%d:%d", &h, &m, &s);
		start[i].start = h * 3600 + m * 60 + s;
		start[i].position = i;
		scanf("%d:%d:%d", &h, &m, &s);
		end[i].end = h * 3600 + m * 60 + s;
		end[i].position = i;
	}
	qsort(start, i, sizeof(struct SNode), compareSnode);
	printf("%s ", ID[start[0].position]);
	qsort(end, i, sizeof(struct ENode), compareEnode);
	printf("%s", ID[end[i-1].position]);
}