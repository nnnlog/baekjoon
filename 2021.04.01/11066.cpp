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

	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		vi vec(n + 1);
		for (auto &i : vec | drop(1)) cin >> i;

		vector<vi> dp(n + 1, vi(n + 1, 1e9)), cost(n + 1, vi(n + 1, 1e9));
		for (int i = n; i >= 1; i--) {
			dp[i][i] = vec[i];
			cost[i][i] = 0;
			for (int j = i + 1; j <= n; j++) {
				for (int k = i; k < j; k++)
					dp[i][j] = min(dp[i][j], (dp[i][k] + dp[k + 1][j])), cost[i][j] = min(cost[i][j], cost[i][k] + cost[k + 1][j]);
				cost[i][j] += dp[i][j];
			}
		}

		cout << cost[1][n] << "\n";
	}
}
