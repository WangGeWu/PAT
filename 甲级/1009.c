#include<stdio.h>
int main()
{
	double Polynomials_one[20];
	double Polynomials_two[20];
	double result[400];
	double Zhi, Xi;
	int num1, num2,temp,m;
	int i, j,k,p;
	scanf("%d", &num1);
	for (i = 0; i < 2 * num1; i++)
	{
		scanf("%lf", &Polynomials_one[i]);
	}
	scanf("%d", &num2);
	for (i = 0; i < 2 * num2; i++)
		scanf("%lf", &Polynomials_two[i]);
	i = 0;
	j = 0;
	while (j<num2 * 2)
	{
		result[i++] = Polynomials_one[0] + Polynomials_two[j++];
		result[i++] = Polynomials_one[1] * Polynomials_two[j++];
	}
	temp = i;
	for (i = 2; i<num1 * 2; i+=2)
		for (j = 0; j < num2 * 2; j+=2)
		{
			Zhi = Polynomials_one[i] + Polynomials_two[j];
			Xi = Polynomials_one[i + 1] * Polynomials_two[j+1];
			k = 0;
			while (result[k]>Zhi&&k<temp)
			{
				k += 2;
			}
			if (result[k] == Zhi&&k<temp)
			{
				result[k + 1] += Xi;
			}
			else if(result[k]<Zhi&&k<temp)
			{
				for (m = temp; m > k; m-=2)
				{
					result[m+1] = result[m-1];
					result[m] = result[m-2];
				}
				result[k] = Zhi;
				result[k+1] = Xi;
				temp += 2;
			}
			else if(k>=temp)
			{
				result[temp] = Zhi;
				result[temp + 1] = Xi;
				temp+=2;
			}
		}
	i = 0;
	j = 0;
	for (i = 1; i < temp; i+=2)
	{
		if (result[i] != 0)
			j++;
	}
	printf("%d", j);
	i = 0;
	while (i<temp)
	{
		if (result[i + 1] == 0)
			i = i + 2;
		else
		{
			printf(" %d %.1lf", (int)result[i], result[i + 1]);
			i = i + 2;
		}
	}
	return 0;
}
