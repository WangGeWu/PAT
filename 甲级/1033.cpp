//贪心算法
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
	double totalPrice=0;//总花费
	double nowprice=0;//此时行驶使用油的单价
	double maxdis=0;//此时可以行驶的最大距离
	double nowdis=0;//此时的距离
	double x = 0;//表示到站点后剩下的油量
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
			for (int i = 1; i <= n&&maxdis >= station[i].dist; i++)//寻找最大行驶距离中油价地狱目前油价的第一个站点
			{
				if (station[i].dist <= nowdis)continue;
				if (nowprice > station[i].price)
				{
					totalPrice += ((station[i].dist - nowdis) / davg-x)*nowprice;//因为下一站点的油价低于此站点，因此只加够可以到达下一站点的油量
					x = 0;
					nowprice = station[i].price;
					nowdis = station[i].dist;
					flag = 1;
					printf("%d->", station[i].node);
					break;
				}
				if (station[i].price < minPrice)//没找到低于目前油价的站点，退而求其次，寻找最低油价的站点
				{
					j = i;
					minPrice = station[i].price;
					minPriceDis = station[i].dist;
				}
			}
			if (flag == 0 && minPrice != inf) {
				totalPrice += (nowprice * (cmax-x));//因为到达的站点油价高于目前站点，所以加满油
				x = cmax - (minPriceDis - nowdis) / davg;//到站点后油有剩余
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