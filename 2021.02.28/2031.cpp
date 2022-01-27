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

int dp[12][1000002];
int nxt[1000002];
int t, n, d, k;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t >> n >> d >> k;
	--d;

	vi vec(n + 1);
	for (int i = 1; i <= n; i++) cin >> vec[i];

	sort(all(vec));
	for (int i = 1; i <= n; i++) nxt[i] = upper_bound(all(vec), vec[i] + d) - vec.begin();

	int ans = 0;
	for (int c = 1; c <= k; c++) {
		for (int i = 1; i <= n; i++) {
			dp[c][nxt[i]] = max(dp[c][nxt[i]], dp[c - 1][i] + nxt[i] - i);
			dp[c][i + 1] = max(dp[c][i + 1], dp[c][i]);
			ans = max(ans, dp[c][nxt[i]]);
		}
	}

	cout << ans;
}
