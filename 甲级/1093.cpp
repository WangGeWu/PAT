//ͳ��Aǰ��P�ĸ�����A����T�ĸ�������ǰA��ɵ�PAT������cntp*cntt;
//�����г��ֵ�A�ۼ�
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