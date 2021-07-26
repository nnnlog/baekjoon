#include <bits/stdc++.h>

using namespace std;

int l[1001], r[1001], dp[1001][1001];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> l[i];
	for (int i = 1; i <= n; i++) cin >> r[i];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			if (abs(l[i] - r[j]) <= 4) dp[i][j] = dp[i - 1][j - 1] + 1;
		}

	cout << dp[n][n];
}
