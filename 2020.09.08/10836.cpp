#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	
	int m, n; cin >> n >> m;

	vector<int> border(2 * n - 1, 1);

	while (m--) {
		int a, b, c; cin >> a >> b >> c;

		for (int i = a; i < a + b; i++) border[i]++;
		for (int i = a + b; i < 2 * n - 1; i++) border[i] += 2;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!j) cout << border[n - i - 1] << ' ';
			else cout << border[n + j - 1] << ' ';
		}
		cout << "\n";
	}
}
