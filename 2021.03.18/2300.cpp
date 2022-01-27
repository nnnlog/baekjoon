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

vl X, Y;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	X.resize(n + 1), Y.resize(n + 1);

	vpll tmp(n);
	for (auto &[a, b] : tmp) cin >> a >> b;
	sort(all(tmp));

	for (int i = 0; i < n; i++) X[i + 1] = tmp[i].first, Y[i + 1] = tmp[i].second;

	vl dp(n + 1, 1e18);
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		ll upY = 0, dnY = 0;
		for (int j = i; j >= 1; j--) {
			ll y = Y[j];
			if (y > 0) upY = max(upY, y);
			else dnY = min(dnY, y);

			ll ok = (X[i] - X[j]);
			ok = max(ok, max(upY, -dnY) * 2);

			dp[i] = min(dp[i], dp[j - 1] + ok);
		}
	}

	cout << dp.back();
}
