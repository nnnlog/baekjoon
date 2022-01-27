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

ll dp_1[1002][1002];
ll dp_2[1002][1002];

ll mp[1002][1002];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m; cin >> n >> m;

	auto get_safe = [&](auto arr, int i, int j) {
		if (arr[i][j] != -1e18) return arr[i][j];
		if (i < 1 || i > n || j < 1 || j > m) return (ll)-1e18;
		return arr[i][j];
	};
	for (auto &a : dp_1) for (auto &b : a) b = -1e18;
	for (auto &a : dp_2) for (auto &b : a) b = -1e18;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> mp[i][j];
	dp_1[n][0] = 0;
	dp_2[n][m + 1] = 0;
	for (int i = n; i >= 1; i--) for (int j = 1; j <= m; j++) dp_1[i][j] = mp[i][j] + max(get_safe(dp_1, i + 1, j), get_safe(dp_1, i, j - 1));
	for (int i = n; i >= 1; i--) for (int j = m; j >= 1; j--) dp_2[i][j] = mp[i][j] + max(get_safe(dp_2, i + 1, j), get_safe(dp_2, i, j + 1));
	//for (int i = 1; i <= n; i++) { for (int j = 1; j <= m; j++) cout << dp_2[i][j] << " "; cout << "\n";}
	ll ans = -1e18;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) ans = max(ans, dp_1[i][j] + dp_2[i][j]);
	cout << ans;
}
