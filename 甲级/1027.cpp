#include<stdio.h>
int main()
{
	int num[3];
	char a[14] = { "0123456789ABC" };
	scanf("%d %d %d", &num[0], &num[1], &num[2]);
	printf("#");
	for (int i = 0; i < 3; i++)
	{
		printf("%c%c",a[num[i]/13],a[num[i] % 13]);
	}
}