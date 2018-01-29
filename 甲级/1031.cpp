#include<stdio.h>
#include<string.h>
int main()
{
	char s[81];
	char draw[30][30];
	int n1, n2, n3,len;
	gets_s(s, 81);
	len = strlen(s);
	n1 = n3 = (len + 2) / 3;
	n2 = (len + 2) / 3 + (len + 2) % 3;
	int indix = 0;
	int i,j;
	for (i = 0; i < 30; i++)
		for (j = 0; j < 30; j++)
			draw[i][j] = ' ';
	for (i = 0; i < n1; i++)
		draw[i][0] = s[indix++];
	for (i = 1; i < n2; i++)
		draw[n1-1][i] = s[indix++];
	for (i = n1 - 2; i >= 0; i--)
		draw[i][n2 - 1] = s[indix++];
	for (i = 0; i <n1; i++)
	{
		for (j = 0; j < n2; j++)
		{
			printf("%c", draw[i][j]);
		}
		printf("\n");
	}
	return 0;
}