#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int hash[256] = {0};
	int flag[256] = { 0 };
	int i;
	char s1[81],s2[81];
	gets_s(s1, 81);
	gets_s(s2, 81);
	for (i = 0; i < strlen(s2); i++)
	{
		if ('a' <= s2[i] && s2[i] <= 'z')//Í³Ò»×ª»»Îª´óÐ´×Ö·û
			s2[i] -= 32;
		hash[s2[i]] = 1;
	}
	for (i = 0; i < strlen(s1); i++)
	{
		if ('a' <= s1[i] && s1[i] <= 'z')
			s1[i] -= 32;
		if (hash[s1[i]] == 0 && flag[s1[i]] == 0)
		{
			printf("%c", s1[i]);
			flag[s1[i]] = 1;
		}
	}
	return 0;
}
