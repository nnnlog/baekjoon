#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define int long long
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

vector<vpii> graph;
vpii par;
vi depth;
const int MX = 16;
vpii sparse[MX + 1];

void dfs(int a, int d) {
	for (const auto &[nxt, w] : graph[a]) if (!par[nxt].first) par[nxt] = {a, w}, depth[nxt] = d + 1, dfs(nxt, d + 1);
}

int get(int s, int k) {
	for (int i = MX; i >= 0; --i) if (k & (1LL << i)) s = sparse[i][s].first;
	return s;
}

int sum(int s, int k) {
	int ret = 0;
	for (int i = MX; i >= 0; --i) if (k & (1LL << i)) ret += sparse[i][s].second, s = sparse[i][s].first;
	return ret;
}

int lca(int u, int v) {
	if (depth[u] != depth[v]) {
		if (depth[u] < depth[v]) swap(u, v);
		for (int k = MX; k >= 0; --k) if (depth[sparse[k][u].first] >= depth[v]) u = sparse[k][u].first;
	}
	if (u == v) return u;
	for (int k = MX; k >= 0; --k)
		if (sparse[k][u].first != sparse[k][v].first)
			u = sparse[k][u].first, v = sparse[k][v].first;
	return par[u].first;
}

main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	graph.resize(n + 1), par.resize(n + 1), depth.resize(n + 1);
	for (auto &i : sparse) i.resize(n + 1);
	par[1] = {1, 0}, depth[1] = 1;
	for (int i = 1; i < n; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		graph[a].emplace_back(b, w);
		graph[b].emplace_back(a, w);
	}
	dfs(1, 1);

	for (int i = 1; i <= n; i++) sparse[0][i] = par[i];
	for (int k = 1; k <= MX; k++)
		for (int i = 1; i <= n; i++)
			sparse[k][i] = {sparse[k - 1][sparse[k - 1][i].first].first,
			                sparse[k - 1][i].second + sparse[k - 1][sparse[k - 1][i].first].second};

	int q;
	cin >> q;
	while (q--) {
		int t, a, b;
		cin >> t >> a >> b;
		int l = lca(a, b);
		//cout << "LCA: " << l << "\n";
		if (t == 1) cout << sum(a, depth[a] - depth[l]) + sum(b, depth[b] - depth[l]) << "\n";
		else {
			int k;
			cin >> k;
			--k;
			int x = depth[a] - depth[l], y = depth[b] - depth[l];
			//cout << "DIST " << x << " " << y << "\n";
			if (x >= k) cout << get(a, k) << "\n";
			else cout << get(b, y - k + x) << "\n";
		}
	}
}
