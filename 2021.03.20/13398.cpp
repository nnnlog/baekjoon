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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, f = 0; cin >> n;
	vi vec(n + 1);
	vector<vi> dp(n + 1, vi(2));

	for (auto &i : vec | drop(1)) cin >> i, f = f || i >= 0;

	if (!f) {
		cout << *max_element(vec.begin() + 1, vec.end());
		return 0;
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = max(dp[i - 1][0] + vec[i], 0);
		dp[i][1] = max(dp[i - 1][1] + vec[i], dp[i - 1][0]);

		ans = max(ans, max(dp[i][0], dp[i][1]));
	}

	cout << ans;
}
