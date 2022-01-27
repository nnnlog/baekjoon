#include <bits/stdc++.h>

using namespace std;

int sum[1025][1025];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= m; y++) {
			int a;
			cin >> a;
			sum[x][y] = sum[x - 1][y] + sum[x][y - 1] - sum[x - 1][y - 1] + a;
		}
	}

	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int ans = sum[x2][y2];
		if (x1 > 1) {
			ans -= sum[x1 - 1][y2];
		}
		if (y1 > 1) {
			ans -= sum[x2][y1 - 1];
		}
		if (x1 > 1 && y1 > 1) ans += sum[x1 - 1][y1 - 1];
		cout << ans << "\n";
	}
}