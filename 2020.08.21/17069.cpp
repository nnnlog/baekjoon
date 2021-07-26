#include <bits/stdc++.h>

using namespace std;

unsigned long long dp[33][33][3]; //dp[i][j][state], state (0: right, 1: 대각선, 2: down)
int table[33][33];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	for (int y = 1; y <= n; y++)
		for (int x = 1; x <= n; x++)
			cin >> table[x][y];

	dp[2][1][0] = 1;

	for (int y = 1; y <= n; y++)
		for (int x = 1; x <= n; x++) {
			if (!table[x][y]) {
				dp[x][y][0] += dp[x - 1][y][0] + dp[x - 1][y][1];
				dp[x][y][2] += dp[x][y - 1][1] + dp[x][y - 1][2];

				if (!table[x - 1][y] && !table[x][y - 1]) dp[x][y][1] = dp[x - 1][y - 1][0] + dp[x - 1][y - 1][1] + dp[x - 1][y - 1][2];
			}
		}


	cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
}
