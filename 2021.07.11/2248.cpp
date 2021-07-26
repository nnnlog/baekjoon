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

ll dp[32][32];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll n, l, k; cin >> n >> l >> k;
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = 1;
		for (int j = 1; j <= i; j++)
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
	}

	while (n > 0) {
		ll first = 0;
		for (int i = 0; i <= l; i++) first += dp[n - 1][i];
		//cout << n << " " << k << "\n";
		if (first >= k) cout << 0;
		else k -= first, --l, cout << 1;
		--n;
	}
}
