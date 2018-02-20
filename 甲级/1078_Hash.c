#include<stdio.h>
#include<stdlib.h>
int visited[19999];
int ToPrime(int n)
{
	if (n == 1)
		return 2;
	int flag = 1;
	while (flag)
	{
		flag = 0;
		for (int i = 2; i*i <= n; i++)
		{
			if (n%i == 0)
			{
				n++;
				flag = 1;
				break;
			}
		}
	}
	return n;
}
int main()
{
	int msize, n;
	int i;
	scanf("%d%d", &msize, &n);
	msize = ToPrime(msize);
	for (i = 0; i < n; i++)
	{
		int key;
		scanf("%d", &key);
		int pos = key%msize;
		if (visited[pos] == 0)
		{
			visited[pos] = 1;
			if (i != 0)
				printf(" ");
			printf("%d", pos);
		}
		else
		{
			int flag = 0;
			int step;
			for (step = 1; step < msize; step++)
			{
				pos = (key + step*step) % msize;
				if (visited[pos] == 0)
				{
					flag = 1;
					visited[pos] = 1;
					if (i != 0)
						printf(" ");
					printf("%d", pos);
					break;
				}
			}
			if (flag == 0)
			{
				if (i != 0)
					printf(" ");
				printf("-");
			}
		}
	}
	return 0;
}
