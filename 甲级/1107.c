#include<stdio.h>
#include<stdlib.h>
int stu[1000];
struct hobnofr
{
  int num;
  int student[1000];
}hob[1000];
int flag[1001];
int cmp(const void*a, const void*b)
{
  return *(int*)a - *(int*)b;
}
int find(int v)
{
  while (stu[v] >= 0)
  {
    v = stu[v];
  }
  return v;
}
void uion(int v1, int v2)
{
  int f1 = find(v1);
  int f2 = find(v2);
  if (f1 != f2)
  {
    stu[f1] += stu[f2];
    stu[f2] = f1;
  }
}
int main()
{
  int n;
  int i, j, k;
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    stu[i] = -1;
  for (i = 0; i < n; i++)
  {
    int m;
    scanf("%d:", &m);
    for (j = 0; j < m; j++)
    {
      int h;
      scanf("%d", &h);
      hob[h].student[hob[h].num++] = i;
      if (hob[h].num > 1)
      {
        for (k = 1; k < hob[h].num; k++)
          uion(hob[h].student[0], hob[h].student[k]);
      }
    }
  }
  qsort(stu, n, sizeof(int), cmp);
  i = 0;
  while (stu[i]< 0 && i < n)
    i++;
  printf("%d\n%d", i, -stu[0]);
  for (j = 1; j < i; j++)
  {
    printf(" %d", -stu[j]);
  }
  return 0;
}
