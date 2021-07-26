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
vl pos;

ll dp[1001][1001][2];

ll solve(int l, int r, int f, int k) {
	if (l == 0 && r == n) return 0;
	ll &ret = dp[l][r][f];
	if (ret != -1) return ret;
	ret = 1e18;
	int curr = f ? r : l;
	if (l > 0) {
		ret = solve(l - 1, r, 0, k - 1) + k * (pos[curr] - pos[l - 1]);
	}
	if (r < n) {
		ret = min(ret, solve(l, r + 1, 1, k - 1) + k * (pos[r + 1] - pos[curr]));
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	memset(dp, -1, sizeof(dp));

	cin >> n >> m;
	pos.resize(n + 1);
	pos[0] = m;
	for (int i = 1; i <= n; i++) cin >> pos[i];
	sort(all(pos));
	int k = find(all(pos), m) - pos.begin();
	cout << solve(k, k, 0, n);
}
