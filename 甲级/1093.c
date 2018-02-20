//统计A前面P的个数，A后面T的个数，当前A组成的PAT数等于cntp*cntt;
//将所有出现的A累加
#include<stdio.h>
int main()
{
	int i;
	int pnum = 0, tnum = 0, result = 0;
	char s[100001];
	scanf("%s", s);
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == 'T')
			tnum++;
	}
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == 'T')tnum--;
		if (s[i] == 'P')pnum++;
		if (s[i] == 'A')result =(result+ tnum*pnum% 1000000007)% 1000000007;
	}
	printf("%d", result);

}
