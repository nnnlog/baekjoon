#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int x, y, k, a[15][15] = { 1, }, t = 0, before, after;
	scanf("%d %d %d", &y, &x, &k);

	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			a[j][i] = 1;
		}
	}

	if (k == 0) {
		after = 1;
	}

	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			++t;
			if (t == k || x * y == t) {
				a[j][i] = a[j - 1][i] + a[j][i - 1];
				if (j - 1 < 0 || i - 1 < 0) {
					a[j][i] = 1;
				}
				before = a[j][i];
				if (k != x * y) {
					int b[15][15] = { 1, };
					for (int q = 0; q < y; q++) {
						for (int p = 0; p < x; p++) {
							b[p][q] = 1;
						}
					}
					i++;
					for (; i < y; i++) {
						for (int j1 = j + 1; j1 < x; j1++) {
							b[j1][i] = b[j1 - 1][i] + b[j1][i - 1];
						}
					}
					after = b[x - 1][y - 1];
				}
				break;
			}
			if (j == 0 || i == 0) {
				continue;
			}
			a[j][i] = a[j - 1][i] + a[j][i - 1];
		}
	}

	printf("%d", before * after);


	return 0;
}
