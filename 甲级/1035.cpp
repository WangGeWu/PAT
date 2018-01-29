#include<stdio.h>
struct node
{
	char id[11];
	char key[11];
}accounts[1001];
int flag[1001];
int main()
{
	int i;
	int n;
	//input
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%s", accounts[i].id);
		getchar();
		scanf("%s", accounts[i].key);
	}
	//process
	int j;
	int cntman = 0;//记录需要修改的账户数目
	int visit;//标记是否进行过修改
	for (i = 0; i < n; i++)
	{
		visit = 0;
		j = 0;
		while (accounts[i].key[j] != '\0')
		{
			if (accounts[i].key[j] == '1')
			{
				visit = 1;
				accounts[i].key[j] = '@';
			}
			else if (accounts[i].key[j] == '0')
			{
				visit = 1;
				accounts[i].key[j] = '%';
			}
			else if (accounts[i].key[j] == 'O')
			{
				visit = 1;
				accounts[i].key[j] = 'o';
			}
			else if(accounts[i].key[j]=='l')
			{
				visit = 1;
				accounts[i].key[j] = 'L';
			}
			j++;
		}
		if (visit == 1)
		{
			flag[cntman++] = i;
		}
	}
	//output
	if (cntman == 0)
	{
		if (n == 1)
			printf("There is 1 account and no account is modified\n");
		else
			printf("There are %d accounts and no account is modified\n",n);
		return 0;
	}
	printf("%d\n", cntman);
	for (i = 0; i < cntman; i++)
	{
		printf("%s %s\n", accounts[flag[i]].id, accounts[flag[i]].key);
	}
	return 0;
}