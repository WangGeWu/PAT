#include<stdio.h>
int main()
{
	int N;
	int a,temp=0,num=0;
	scanf("%d", &N);
	while (N)
	{
		scanf("%d", &a);
		if (a > temp)num += (a - temp) * 6;
		else if (a < temp)num += (temp - a) * 4;
		temp = a;
		num += 5;
		N--;
	}
	printf("%d", num);
	return 0;
}
