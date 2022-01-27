#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;
using namespace views;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vld;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pld> vpld;
typedef unordered_map<int, int> mpii;

ld dist(pll a, pll b) {
	return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cout.precision(15);
	cout << fixed;

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vpll vec(n + 1);
		for (auto &[a, b] : vec | drop(1)) cin >> a >> b;
		vector<vld> dp(n + 1, vld(n + 1, 1e18));
		dp[1][1] = 0;
		for (int i = 1; i < n; i++) {
			for (int j = 1; j < n; j++) {
				int k = max(i, j);
				dp[k + 1][j] = min(dp[k + 1][j], dp[i][j] + dist(vec[i], vec[k + 1]));
				dp[i][k + 1] = min(dp[i][k + 1], dp[i][j] + dist(vec[j], vec[k + 1]));
			}
		}
		ld ans = dp[n][n];
		for (int i = 1; i < n; i++) ans = min(ans, dp[n][i] + dist(vec[i], vec[n]));
		cout << ans << "\n";
	}
}
