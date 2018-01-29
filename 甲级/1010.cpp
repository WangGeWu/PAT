#include<stdio.h>
#include<math.h>
#include<string.h>
int map[256];//存放字符对应的数字
long long ToTen(char a[], long long radix)
{
	long long ans = 0;
	int len = strlen(a);
	for (int i = 0; i<len; i++)
	{
		ans = ans*radix + map[a[i]];
	}
	return ans;
}
long long Low(char a[])
{
	int max = -1;
	int len;
	len = strlen(a);
	for (int i = 0; i < len; i++)
	{
		if (map[a[i]] > max)
			max = map[a[i]];
	}
	return max + 1;

}
long long judge(long long NumKnowed, char a[])
{
	long long low, high;
	long long ans;
	long long radix;
	long long mid;
	low = Low(a);
	if (low > NumKnowed)high = low + 1;
	else high = NumKnowed + 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		ans = ToTen(a, mid);
		if (ans > NumKnowed||ans<0)//?
			high = mid-1;
		else if (ans < NumKnowed)
			low = mid+1;
		else
			return mid;
	}
	return -1;
}
int main()
{
	char N1[11], N2[11];
	long long num_knowed, num_notknow;
	int radix;
	int tag;
	long long flag;
	int i;
	char c;
	scanf("%s%s%d%d", N1, N2, &tag, &radix);
	for (c = '0'; c <= '9'; c++)
		map[c] = c - '0';
	for (c = 'a'; c <= 'z'; c++)
		map[c] = c - 'a' + 10;
	if (tag == 1)
	{
		num_knowed = ToTen(N1, radix);
		flag = judge(num_knowed, N2);
	}
	else 
	{
		num_knowed = ToTen(N2, radix);
		flag = judge(num_knowed, N1);
	}
	if (flag == -1)
		printf("Impossible\n");
	else
		printf("%lld\n", flag);
	return 0;
}