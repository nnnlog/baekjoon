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

	ll d, m; cin >> d >> m;
	vector<vl> dp(d + 1, vl(d/2 + 1));
	dp[0][0] = 1;
	for (int i = 1; i <= d; i++) {
		for (int j = i != d; j < dp[i].size(); j++) {
			if (j) dp[i][j] += dp[i - 1][j - 1];
			dp[i][j] %= m;
			if (j + 1 < dp[i].size()) dp[i][j] += dp[i - 1][j + 1];
			dp[i][j] %= m;
		}
	}
	cout << dp[d][0];
}
