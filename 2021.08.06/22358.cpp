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

	int n, m, k, s, t; cin >> n >> m >> k >> s >> t;
	vector<vpii> graph(n + 1);
	auto rev_graph = graph;
	while (m--) {
		int u, v, w; cin >> u >> v >> w;
		graph[u].emplace_back(v, w);
		rev_graph[v].emplace_back(u, w);
	}

	vector<vl> dp(k + 1, vl(n + 1, -1));
	dp[0][s] = 0;
	ll ans = -1;
	for (int i = 0; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			if (dp[i][j] < 0) continue;
			for (auto &[v, w] : graph[j]) {
				ll nxt = dp[i][j] + w;
				dp[i][v] = max(dp[i][v], nxt);
			}
			if (i < k) {
				for (auto &[v, w] : rev_graph[j]) {
					dp[i + 1][v] = max(dp[i + 1][v], dp[i][j]);
				}
			}
		}
		ans = max(ans, dp[i][t]);
	}
	cout << ans;
}
