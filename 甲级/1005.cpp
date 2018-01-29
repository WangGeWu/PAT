#include<stdio.h>
#include<string.h>
int main()
{
	int N;
	int temp = 0;
	int i;
	char S;
	char A[101];
	scanf("%c", &S);
	while (S!='\n')
	{
		temp += S - '0';
		scanf("%c", &S);
	}
	sprintf(A, "%d", temp);
	i = 0;
	while (A[i]!='\0')
	{

		if (i == 0)
		{
			switch (A[i])
			{
			case '1':printf("one"); break;
			case '2':printf("two"); break;
			case '3':printf("three"); break;
			case '4':printf("four"); break;
			case '5':printf("five"); break;
			case '6':printf("six"); break;
			case '7':printf("seven"); break;
			case '8':printf("eight"); break;
			case '9':printf("nine"); break;
			case '0':printf("zero"); break;
			}
		}
		else {
			switch (A[i])
			{
			case '1':printf(" one"); break;
			case '2':printf(" two"); break;
			case '3':printf(" three"); break;
			case '4':printf(" four"); break;
			case '5':printf(" five"); break;
			case '6':printf(" six"); break;
			case '7':printf(" seven"); break;
			case '8':printf(" eight"); break;
			case '9':printf(" nine"); break;
			case '0':printf(" zero"); break;
			}
		}
		i++;
	}
	return 0;
}