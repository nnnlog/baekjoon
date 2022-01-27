#include <bits/stdc++.h>

using namespace std;

typedef long long ull;

ull dp[101][21];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n;
	cin >> n;

	int t; cin >> t;
	dp[1][t] = 1;
	for (int i = 2; i <= n; i++) {
		int a;
		cin >> a;
		if (i == n) cout << dp[i - 1][a];
		else
			for (int k = 0; k <= 20; k++) {
				if (!dp[i - 1][k]) continue;
				if (k + a <= 20) dp[i][k + a] += dp[i - 1][k];
				if (k - a >= 0) dp[i][k - a] += dp[i - 1][k];
			}
	}
}
