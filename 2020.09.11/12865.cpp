#include <bits/stdc++.h>

using namespace std;

int dp[100001];
pair<int, int> val[101];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);

	int n, m, ans = 1;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> val[i].first >> val[i].second;

	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int w = m; w >= 0 && w >= val[i].first; w--) {
			dp[w] = max(dp[w], dp[w - val[i].first] + val[i].second);
			ans = max(ans, dp[w]);
		}
	}

	cout << ans - 1;
}
