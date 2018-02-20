#include<stdio.h>
int main()
{
	int n, k;
	int array[40];
	int i = 0;
	scanf("%d %d", &n, &k);
	if (n == 0)
	{
		printf("Yes\n");
		printf("0");
		return 0;
	}
	while (n)
	{
		array[i++] = n%k;
		n = n / k;
    }
	int pos = i-1;
	int temp = i;
	i = 0;
	while ((array[i] == array[pos]) && (i++ < pos--));
	if (i >= pos)
		printf("Yes\n");
	else(printf("No\n"));
	for (i = temp-1; i>=0; i--)
	{
		printf("%d",array[i]);
		if(i>0)
		printf(" ");
	}
	return 0;
}
