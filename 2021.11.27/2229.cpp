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

	int n; cin >> n;
	vi vec(n + 1), dp(n + 1);
	for (int &i : vec | views::drop(1)) cin >> i;
	for (int i = 1; i <= n; i++) {
		int mn = 1e9, mx = 0;
		for (int j = i; j > 0; j--) {
			mn = min(mn, vec[j]);
			mx = max(mx, vec[j]);

			dp[i] = max(dp[i], dp[j - 1] + mx - mn);
		}
	}

	cout << dp.back();
}
