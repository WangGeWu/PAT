#include<stdio.h>
int main()
{
	int galleon1, sickle1, knut1;
	int galleon2;
	int sickle2, knut2;
	scanf("%d.%d.%d", &galleon1, &sickle1, &knut1);
	scanf("%d.%d.%d", &galleon2, &sickle2, &knut2);
	int res_galleon, res_sickle, res_knut;
	res_knut = (knut1 + knut2) % 29;
	res_sickle = (sickle1 + sickle2 + (knut1 + knut2) / 29)%17;
	res_galleon = (galleon1 + galleon2 + (sickle1 + sickle2 + (knut1 + knut2) / 29)/17);
	printf("%d.%d.%d", res_galleon, res_sickle, res_knut);
}