#include <stdio.h>

int UF[300002], vis[300002];

int find(int a) {
	return UF[a] = UF[a] == a ? a : find(UF[a]);
}

void merge(int a, int b) {
	int x = find(a), y = find(b);
	UF[x] = y;
	printf("LADICA\n");
}

int main() {
	int n, l;
	scanf("%d %d", &n, &l);
	for (int i = 1; i <= l; i++) UF[i] = i;

	for (int i = 1; i <= n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		if (!vis[a]) {
			vis[a] = 1;
			merge(a, b);
		}
		else if (!vis[b]) {
			vis[b] = 1;
			merge(b, a);
		}
		else if (!vis[find(a)]) {
			vis[find(a)] = 1;
			merge(a, b);
		}
		else if (!vis[find(b)]) {
			vis[find(b)] = 1;
			merge(b, a);
		}
		else printf("SMECE\n");
	}
}
