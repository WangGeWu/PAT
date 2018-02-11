#include <stdio.h>
#include <stdlib.h>
#define maxn 100000
struct NODE {
	int address, key, next, num = 2 * maxn;
}node[maxn];
int flag[maxn];
int cmp1(const void* a, const void* b) 
{
	return ((struct NODE*)a)->num - ((struct NODE*)b)->num;
}
int main() {
	int begin, n, cnt1 = 0, cnt2 = 0, a;
	scanf("%d%d", &begin, &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		scanf("%d%d", &node[a].key, &node[a].next);
		node[a].address = a;
	}
	for (int i = begin; i != -1; i = node[i].next) {
		if (flag[abs(node[i].key)] == false) {
		    flag[abs(node[i].key)] = true;
			node[i].num = cnt1;
			cnt1++;
		}
		else {
			node[i].num = maxn + cnt2;
			cnt2++;
		}
	}
	qsort(node,maxn,sizeof(struct NODE),cmp1);
	int cnt = cnt1 + cnt2;
	for (int i = 0; i < cnt; i++) {
		if (i != cnt1 - 1 && i != cnt - 1) {
			printf("%05d %d %05d\n", node[i].address, node[i].key, node[i + 1].address);
		}
		else {
			printf("%05d %d -1\n", node[i].address, node[i].key);
		}
	}
	return 0;
}