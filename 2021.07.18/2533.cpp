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

vi vis;
vector<vi> graph, dp;
int solve(int u, int i, int par = 0) {
	int &ret = dp[u][i];
	if (ret) return ret;
	for (const auto &v : graph[u])
		if (par != v) {
			int w = solve(v, 1, u);
			if (i) w = min(w, solve(v, 0, u));
			ret += w;
		}
	if (i) ++ret;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	vis.resize(n + 1), graph.resize(n + 1), dp.assign(n + 1, vi(2));
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	cout << min(solve(1, 0), solve(1, 1));
}
