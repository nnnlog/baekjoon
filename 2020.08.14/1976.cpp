#include <bits/stdc++.h>

using namespace std;

int UF[200];

int find(int a) {
	return UF[a] = UF[a] == a ? a : find(UF[a]);
}

void merge(int a, int b) {
	UF[find(a)] = find(b);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, m; cin >> n >> m;

	for (int i = 0; i < n; i++) UF[i] = i;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			int a; cin >> a;
			if (a) merge(i, j);
		}

	int a; cin >> a;
	int root = find(--a);
	for (int i = 1; i < m; i++) {
		cin >> a;
		if (find(--a) != root) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}
