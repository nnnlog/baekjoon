#include <bits/stdc++.h>

using namespace std;

int UF[1000001];

int find(int a) {
	return UF[a] = a == UF[a] ? a : find(UF[a]);
}

void merge(int a, int b) {
	int x = find(a), y = find(b);
	UF[x] = y;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);

	for (int i = 1; i <= 1000000; i++) UF[i] = i;

	int n, m;
	cin >> n >> m;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (!a) {
			merge(b, c);
		} else {
			cout << (find(b) == find(c) ? "YES" : "NO") << "\n";
		}
	}
}