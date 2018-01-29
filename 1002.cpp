#include<stdio.h>
#include<stdlib.h>
int main()
{
	int x;
	float  *data_one,*data_two;
	int k1,k2,i;
	int Ptr_one = 0, Ptr_two = 0;
	float Resurt_data[40];
	scanf("%d", &k1);
	if (k1 > 10)
	{
		printf("No");
		return 0;
	}
	data_one=(float*)malloc(2*k1*sizeof(float));
	for (i = 0; i < 2 * k1; i++)
	{
		scanf("%f", &data_one[i]);
	}
	scanf("%d", &k2);
	if (k2 > 10)
	{
		printf("No");
		return 0;
	}
	data_two = (float*)malloc(2 * k2 * sizeof(float));
	for (i = 0; i < 2 * k2; i++)
	{
		scanf("%f",&data_two[i]);
	}
	i = 0;
	while (Ptr_one < 2 * k1&&Ptr_two < 2 * k2)
	{
		if (data_one[Ptr_one] > data_two[Ptr_two])
		{
			Resurt_data[i++] = data_one[Ptr_one++];
			Resurt_data[i++] = data_one[Ptr_one++];
		}
		else if (data_one[Ptr_one] < data_two[Ptr_two])
		{
			Resurt_data[i++] = data_two[Ptr_two++];
			Resurt_data[i++] = data_two[Ptr_two++];
		}
		else
		{
			if (data_one[Ptr_one + 1] + data_two[Ptr_two + 1] != 0)
			{
				Resurt_data[i++] = data_one[Ptr_one];
				Resurt_data[i++] = data_one[Ptr_one + 1] + data_two[Ptr_two + 1];
			}
				Ptr_one += 2;
				Ptr_two += 2;
		}
	}
	if (Ptr_one >= 2 * k1)
	{
		while(Ptr_two<2*k2)
		Resurt_data[i++] = data_two[Ptr_two++];
	}
	else
	{
		while (Ptr_one<2 * k1)
			Resurt_data[i++] = data_one[Ptr_one++];
	}
	if (i / 2 == 0)
	{
		printf("0\n");
		return 0;
	}
	else 
	printf("%d ", i/2);
	k1 = i;
	for (i = 0; i < k1; i++)
	{
		if (i != k1 - 1) {
			if (i % 2 == 0)
			{
				x = (int)Resurt_data[i];
				printf("%d ", x);
			}
			else
				printf("%.1f ", Resurt_data[i]);
		}
		else
			printf("%.1f\n", Resurt_data[i]);
	}
	free(data_one);
	free(data_two);
}