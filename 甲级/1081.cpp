#include<stdio.h>
#include<stdlib.h>
long long gcd(long long a, long long b)
{
	if (b == 0)
		return abs(a);
	else
		return gcd(b, a%b);
}
int main()
{
	int n;
	int i;
	long long gcdnum, suma=0, sumb=1, a, b;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%lld/%lld", &a, &b);
		gcdnum = gcd(a,b);//求最大公约数
		a = a / gcdnum;
		b = b / gcdnum;
		suma = suma*b + sumb*a;
		sumb = sumb*b;
		gcdnum = gcd(suma, sumb);
		suma = suma / gcdnum;
		sumb = sumb / gcdnum;
	}
	long long num = suma / sumb;
	suma = suma - num*sumb;
	if (num != 0 && suma != 0)
	{
		printf("%lld ", num);
		printf("%lld/%lld", suma, sumb);
	}
	else if (suma == 0 && num == 0)
		printf("0");
	else if (suma == 0 && num != 0)
		printf("%lld", num);
	else
		printf("%lld/%lld", suma, sumb);
    return 0;
}