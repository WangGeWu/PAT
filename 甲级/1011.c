#include<stdio.h>
int Find(float a[]);
int main()
{
	float data[3][3];
	char c[3] = { 'W','T','L' };
	int i, j;
	float money=1;
	int position;
	for(i=0;i<3;i++)
		for (j = 0; j < 3; j++)
		{
			scanf("%f", &data[i][j]);
		}
	for (i = 0; i < 3; i++)
	{
		position = Find(data[i]);
		printf("%c ", c[position]);
		money *= data[i][position];
	}
	money = (money*0.65 - 1) * 2;
	printf("%.2f\n", money+0.005);
	return 0;
}
int Find(float a[])
{
	int i;
	int position;
    float max=-1;
	for(i=0;i<3;i++)
		if (max < a[i])
		{
			max = a[i];
			position = i;
		}
	return position;
}
