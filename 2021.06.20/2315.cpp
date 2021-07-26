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

int n, m;
vl sum, pos;

ll dp[1001][1001][2];

ll solve(int l, int r, int f) {
	if (l == 1 && r == n) return 0;
	ll &ret = dp[l][r][f];
	if (ret != -1) return ret;
	ret = 1e18;
	int curr = f ? r : l;
	ll w = sum[n] - sum[r] + sum[l - 1];
	if (l > 1) {
		ret = solve(l - 1, r, 0) + w * (pos[curr] - pos[l - 1]);
	}
	if (r < n) {
		ret = min(ret, solve(l, r + 1, 1) + w * (pos[r + 1] - pos[curr]));
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	memset(dp, -1, sizeof(dp));

	cin >> n >> m;
	sum.resize(n + 1), pos.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> pos[i];
		ll a; cin >> a;
		sum[i] = sum[i - 1] + a;
	}
	cout << solve(m, m, 0);
}
