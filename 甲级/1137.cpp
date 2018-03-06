#include<iostream>
#include<cstdio>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
struct node
{
	int program;
	string id;
	int mid=-1;
	int fin=-1;
	int g=-1;//×îÖÕ³É¼¨
}stu[30001];
map<string, int>strTonum;
bool cmp(node a,node b)
{
	if (a.g != b.g)
		return a.g > b.g;
	else
		return a.id < b.id;
}
int main()
{
	int p, m, n;
	cin >> p >> m >> n;
	int i;
	int cnt=0;
	string id;
	int num;
	for (i = 0; i < p; i++)
	{
		cin >> id >> num;
		strTonum[id] = cnt;
		stu[cnt].id = id;
		stu[cnt++].program = num;
	}
	for (i = 0; i < m; i++)
	{
		cin >> id >> num;
		if (strTonum.find(id) == strTonum.end())
		{
			strTonum[id] = cnt;
			stu[cnt++].id = id;
		}
		stu[strTonum[id]].mid = num;
	}
	for (i = 0; i < n; i++)
	{
		cin >> id >> num;
		if (strTonum.find(id) == strTonum.end())
		{
			strTonum[id] = cnt;
			stu[cnt++].id = id;
		}
		stu[strTonum[id]].fin=num;
	}
	for (i = 0; i < cnt; i++)
	{
		if (stu[i].program >= 200)
		{
			if (stu[i].mid > stu[i].fin)
				stu[i].g = (int)(((float)stu[i].mid*0.4 + (float)stu[i].fin*0.6+0.5));
			else
				stu[i].g = stu[i].fin;
		}
	}
	sort(stu,stu+cnt, cmp);
	i = 0;
	while (i<cnt)
	{
		if (stu[i].g < 60)break;
		cout << stu[i].id;
		printf(" %d %d %d %d\n",stu[i].program,stu[i].mid, stu[i].fin, stu[i].g);
		i++;
	}
	return 0;
}