#include<stdio.h>
#include<string.h>
int main()
{
	char s1[10001];
	char s2[10001];
	int hash[257];
	int i;
	for (i = 0; i < 257; i++)
		hash[i] = 0;
	gets_s(s1, 10001);
	gets_s(s2,10001);
	int len2 = strlen(s2);
	for (i = 0; i<len2; i++)
	{
		hash[s2[i]] = 1;
	}
	printf("%c", s2[0]);
	int len1 = strlen(s1);
	for (i = 0; i < len1; i++)
	{
		if (hash[s1[i]] != 1)
			printf("%c", s1[i]);
	}
	return 0;
}