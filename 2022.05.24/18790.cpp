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

bitset<501> dp[1001][501];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	vi vec(2 * n);
	for (int &i : vec | views::drop(1)) cin >> i;

	dp[0][0][0] = 1;
	for (int i = 1; i < 2 * n; i++) {
		for (int j = 1; j <= min(i, n); j++) {
			for (int k = 0; k < n; k++) {
				dp[i][j][k] = dp[i - 1][j][k] || dp[i - 1][j - 1][(k - vec[i] + n) % n];
			}
		}
	}

	if (!dp[2 * n - 1][n][0]) return cout << -1, 0;
	int j = n;
	int k = 0;
	for (int i = 2 * n - 1; i >= 1; i--) {
		if (!dp[i - 1][j][k]) {
			j--;
			k = (k - vec[i] + n) % n;
			cout << vec[i] << " ";
		}
	}
}
