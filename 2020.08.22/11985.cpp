#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

ull orange[20001], dp[20001];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);

	ull n, m, k; cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> orange[i];
		dp[i] = k * i;
	}

	for (int i = 0; i < n; i++) {
		ull min_v = orange[i + 1], max_v = orange[i + 1];
		for (int j = 1; j <= m && i + j <= n; j++) {
			min_v = min(min_v, orange[i + j]);
			max_v = max(max_v, orange[i + j]);
			dp[i + j] = min(dp[i + j], dp[i] + k + j * (max_v - min_v));
		}
	}
	cout << dp[n];
}
