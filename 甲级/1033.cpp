//̰���㷨
#include<stdio.h>
#include<stdlib.h>
#define inf 9999999
struct node
{
	int node;
	double price;
	double dist;
}station[501];
int cmp(const void *a, const void *b)
{
	if ((((struct node*)a)->dist - ((struct node*)b)->dist) > 0)
		return 1;
	else if ((((struct node*)a)->dist - ((struct node*)b)->dist) < 0)
		return -1;
	else 
		return 0;
}
int main()
{
	double totalPrice=0;//�ܻ���
	double nowprice=0;//��ʱ��ʻʹ���͵ĵ���
	double maxdis=0;//��ʱ������ʻ��������
	double nowdis=0;//��ʱ�ľ���
	double x = 0;//��ʾ��վ���ʣ�µ�����
	int i;
	int k;
	int cmax, d, davg, n;
	//input
	scanf("%d %d %d %d", &cmax, &d, &davg, &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%lf %lf", &station[i].price, &station[i].dist);
		station[i].node = i-1;
	}
	station[0].dist = d; station[0].price = 0.0; station[0].node = n;
	//process
	qsort(station, n+1, sizeof(struct node), cmp);
	if (station[0].dist > 0)
	{
		printf("The maximum travel distance = 0.00");
		return 0;
	}
	else
	{
		nowprice = station[0].price;
		while (nowdis < d)
		{
			maxdis = nowdis + cmax*davg;
			int flag = 0;
			double minPriceDis = 0, minPrice = inf;
			for (int i = 1; i <= n&&maxdis >= station[i].dist; i++)//Ѱ�������ʻ�������ͼ۵���Ŀǰ�ͼ۵ĵ�һ��վ��
			{
				if (station[i].dist <= nowdis)continue;
				if (nowprice > station[i].price)
				{
					totalPrice += ((station[i].dist - nowdis) / davg-x)*nowprice;//��Ϊ��һվ����ͼ۵��ڴ�վ�㣬���ֻ�ӹ����Ե�����һվ�������
					x = 0;
					nowprice = station[i].price;
					nowdis = station[i].dist;
					flag = 1;
					printf("%d->", station[i].node);
					break;
				}
				if (station[i].price < minPrice)//û�ҵ�����Ŀǰ�ͼ۵�վ�㣬�˶�����Σ�Ѱ������ͼ۵�վ��
				{
					j = i;
					minPrice = station[i].price;
					minPriceDis = station[i].dist;
				}
			}
			if (flag == 0 && minPrice != inf) {
				totalPrice += (nowprice * (cmax-x));//��Ϊ�����վ���ͼ۸���Ŀǰվ�㣬���Լ�����
				x = cmax - (minPriceDis - nowdis) / davg;//��վ�������ʣ��
				nowprice = minPrice;
				nowdis = minPriceDis;
				printf("%d->", station[j].node);
			}
			if (flag == 0 && minPrice == inf) {
				nowdis += cmax * davg;
				printf("The maximum travel distance = %.2f", nowdis);
				return 0;
			}
		}
	}
	//output
	printf("%.2f", totalPrice);
	return 0;
}