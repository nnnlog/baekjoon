#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

int cost[301][301], dp[301][301], trace[301][301];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		for (int j = 1; j <= m; j++) cin >> cost[j][i];
	}

	int ans = 0, mx = 0;
	for (int i = 1; i <= m; i++) {
		for (int c = 1; c <= n; c++) {
			for (int prev = 0; prev <= c; prev++) {
				int _new = cost[i][c - prev] + dp[i - 1][prev];
				if (_new > dp[i][c]) {
					dp[i][c] = _new;
					trace[i][c] = prev;
				}
			}
			ans = max(ans, dp[i][c]);
			if (dp[i][c] == ans) {
				mx = c;
			}
		}
	}

	cout << ans << "\n";

	vector<int> vec;
	for (int i = m; i >= 1; i--) {
		vec.push_back(mx - trace[i][mx]);
		mx = trace[i][mx];
	}

	for (auto it = vec.rbegin(); it < vec.rend(); ++it) cout << *it << " ";
}
