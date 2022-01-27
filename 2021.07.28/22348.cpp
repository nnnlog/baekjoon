#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int mod = 1e9 + 7;

	vector<vl> dp(sqrt(200000) + 1, vl(50001));
	//for (auto &i : dp[0]) i = 1;
	dp[0][0] = 1;
	for (int k = 1; k < dp.size(); k++) {
		for (int i = 0; i < 50001; i++) {
			dp[k][i] = dp[k - 1][i];
			if (i >= k) dp[k][i] += dp[k - 1][i - k], dp[k][i] %= mod;
		}
	}
	auto sum = dp;
	for (int k = 1; k < sum.size(); k++) {
		for (int i = 1; i < 50001; i++) {
			sum[k][i] += sum[k][i - 1];
			sum[k][i] %= mod;
		}
	}

	int T;
	cin >> T;
	while (T--) {
		int a, b;
		cin >> a >> b;
		ll ans = 0;
		for (int k = 1; k <= sqrt(2 * (a + b)); k++) {
			int idx = k * (k + 1) / 2 - b - 1;
			if (idx > a) break;
			ans += sum[k][a];
			if (idx >= 0) ans -= sum[k][idx], ans += mod;
            ans %= mod;
		}
		cout << ans << "\n";
	}
}
