#include<stdio.h>
#include<string.h>
int main()
{
	int n;
	int cnt = 0;
	double num=0;
	int i, j;
	scanf("%d", &n);
	char s1[50];
	char s2[50];
	for (i = 0; i < n; i++)
	{
		int flag = 1;
		double temp;
		scanf("%s", s1);
		sscanf(s1, "%lf", &temp);
		sprintf(s2, "%.2lf", temp);
		for (j = 0; j < strlen(s1); j++)
			if (s1[j] != s2[j])
			{
				flag = 0;
				break;
			}
		if (flag == 0||temp<-1000||temp>1000)
			printf("ERROR: %s is not a legal number\n", s1);
		else 
		{
			cnt++;
			num += temp;
		}
	}
	if (cnt == 1)
		printf("The average of %d number is %.2lf", cnt, num / cnt);
	else if (cnt > 1)
		printf("The average of %d numbers is %.2lf", cnt, num / cnt);
	else
		printf("The average of 0 numbers is Undefined");
	return 0;
}