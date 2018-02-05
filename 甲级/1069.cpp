#include<stdio.h>
#include<stdlib.h>
int cmp2(const void *a, const void *b)
{
	return *(char*)a > *(char*)b;
}
int main()
{
	int i;
	char m[5];
	char low[5], high[5];
	scanf("%s", m);
	int cnt;
	int res=atoi(m);
	while (1)
	{
		cnt = 0;
		while (res)
		{
			m[cnt++] = res % 10 + '0';
			res = res / 10;
		}
		for (i = cnt; i < 4; i++)
			m[i] = '0';
		qsort(m, 4, sizeof(char), cmp2);
		for (i = 0; i < 4; i++)
		{
			low[i] = m[i];
			high[i] = m[3 - i];
		}
		res = atoi(high) - atoi(low);
		printf("%04d - %04d = %04d\n", atoi(high), atoi(low), res);
		if (res == 6174||res==0)
			break;
	}
	return 0;
}