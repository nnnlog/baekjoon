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

vi value;
vector<vi> graph;
vector<vl> dp;

ll ans = -1e18;

void solve(int u) {
	dp[u][0] = dp[u][1] = value[u];
	dp[u][2] = -1e18;
	vl tmp;
	for (int v : graph[u]) {
		solve(v);
		dp[u][2] = max(dp[u][2], dp[v][2]);
		if (dp[v][0] > 0) dp[u][0] += dp[v][0];
		else dp[u][2] = max(dp[u][2], dp[v][1]);
		dp[u][1] = max(dp[u][1], dp[v][1]);
		tmp.push_back(dp[v][1]);
	}
	sort(all(tmp), greater<>());
	if (tmp.size() >= 2) ans = max(ans, tmp[0] + tmp[1]);
	dp[u][1] = max(dp[u][1], dp[u][0]);
	ans = max(ans, dp[u][0] + dp[u][2]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	value.resize(n + 1), graph.resize(n + 1);
	dp.assign(n + 1, vl(3));
	for (int i = 1; i <= n; i++) {
		int p; cin >> value[i] >> p;
		if (p > 0) graph[p].push_back(i);
	}
	solve(1);
	cout << ans;
}
