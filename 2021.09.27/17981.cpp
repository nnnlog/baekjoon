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

	ll s, p, m, n; cin >> s >> p >> m >> n;
	vi vec(n);
	vl dp(n + 1, 1e18);
	for (int &i : vec) cin >> i;
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		dp[i + 1] = min(dp[i + 1], dp[i] + s);
		int idx = upper_bound(all(vec), vec[i] + m - 1) - vec.begin();
		dp[idx] = min(dp[idx], dp[i] + p);
	}
	cout << dp.back();
}
