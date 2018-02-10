#include<stdio.h>
int hash[257];
int main()
{
	char s1[1001], s2[1001];
	scanf("%s%s", s1, s2);
	int i = 0;
	while (s1[i] != '\0')
	{
		hash[s1[i]]++;
		i++;
	}
	int cnt = 0;
	i = 0;
	while (s2[i] != '\0')
	{
		hash[s2[i]]--;
		if (hash[s2[i]] < 0)
			cnt++;
		i++;
	}
	if (cnt != 0)
		printf("No %d", cnt);
	else
	{
		for (i = 0; i < 257; i++)
			cnt += hash[i];
		printf("Yes %d", cnt);
	}
	return 0;
}