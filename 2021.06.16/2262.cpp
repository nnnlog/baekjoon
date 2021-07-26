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

	int n; cin >> n;
	vi vec(n + 1);
	for (auto &i : vec | drop(1)) cin >> i;
	vector<vi> dp(n + 1, vi(n + 1, 1e9));
	vector<vi> C(n + 1, vi(n + 1, 1e9));
	for (int i = n; i >= 1; --i) {
		dp[i][i] = 0;
		C[i][i] = vec[i];
		for (int j = i; j <= n; j++) {
			for (int k = i; k < j; k++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + abs(C[i][k] - C[k + 1][j]));
				C[i][j] = min(C[i][j], min(C[i][k], C[k + 1][j]));
			}
		}
	}
	cout << dp[1][n];
}
