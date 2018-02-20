#include<stdio.h>
int flag = 1;
int pre_order[50000];
int in_order[50000];
int post_order[50000];
void preinTopost(int pre,int in,int post,int num)
{
	if (num <= 0)
		return;
	int i = in;
	while (in_order[i] != pre_order[pre])i++;
	int l = i - in; int r = num -l - 1;
	post_order[post + num - 1] = in_order[i];
	if (post + num - 1 == 0)
	{
		printf("%d", in_order[i]);
		flag = 0;
		return;
	}
	if(flag)
		preinTopost(pre+1,in,post,l);
	if (flag)
		preinTopost(pre + l + 1, i + 1, post + l, r);
}
int main()
{
	int n;
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &pre_order[i]);
	for (i = 0; i < n; i++)
		scanf("%d", &in_order[i]);
	preinTopost(0,0,0,n);
	return 0;
}
