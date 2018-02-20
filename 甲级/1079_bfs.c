//bfs
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double cnt = 0;
int n;
double p, r;
struct node
{
  double num;
  int *child;
  int childnum;
  int deep;
}tree[100001];
int queue[110000];
int rear = -1, front = -1;
void bfs(int v)
{
  queue[++rear] = v;
  while (rear != front)
  {
    int node = queue[++front];
    if (tree[node].childnum == 0)
    {
      cnt += tree[node].num * pow(1 + r, tree[node].deep);
    }
    for (int i = 0; i < tree[node].childnum; i++)
    {
      tree[tree[node].child[i]].deep = tree[node].deep + 1;
      queue[++rear]=tree[node].child[i];
    }
  }
}
int main()
{
  int i, j;
  scanf("%d%lf%lf", &n, &p, &r);
  r = r / 100;
  for (i = 0; i < n; i++)
  {
    int m;
    scanf("%d", &m);
    tree[i].childnum = m;
    if (m)
    {
      tree[i].child = (int*)malloc(sizeof(int)*m);
      for (j = 0; j < m; j++)
      {
        scanf("%d", &tree[i].child[j]);
      }
    }
    else
      scanf("%lf", &tree[i].num);
  }
  bfs(0);
  cnt = cnt*p;
  printf("%.1lf", cnt);
  return 0;
}
