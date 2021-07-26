#include <bits/stdc++.h>

using namespace std;

int sum[1001][1001][3];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);

	int m, n, q; cin >> m >> n >> q;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++) {
			char c; cin >> c;
			for (int k = 0; k < 3; k++) {
				sum[i][j][k] += sum[i - 1][j][k];
				sum[i][j][k] += sum[i][j - 1][k];
				sum[i][j][k] -= sum[i - 1][j - 1][k];
			}

			if (c == 'J') sum[i][j][0]++;
			else if (c == 'O') sum[i][j][1]++;
			else sum[i][j][2]++;
		}

	while (q--) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		//cout << sum[c][d][0] << " " << sum[a][b][0] << "\n";
		for (int i = 0; i < 3; i++) {
			cout << sum[c][d][i] - sum[a - 1][d][i] - sum[c][b - 1][i] + sum[a - 1][b - 1][i] << " ";
		}
		cout << "\n";
	}
}
