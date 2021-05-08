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

vector<vi> graph;
vi par, depth;
const int MX = 16;
vi sparse[MX + 1];

void dfs(int a, int d) {
	for (const auto &nxt : graph[a]) if (!par[nxt]) par[nxt] = a, depth[nxt] = d + 1, dfs(nxt, d + 1);
}

int lca(int u, int v) {
	if (depth[u] != depth[v]) {
		if (depth[u] < depth[v]) swap(u, v);
		for (int k = MX; k >= 0; --k) if (depth[sparse[k][u]] >= depth[v]) u = sparse[k][u];
	}
	if (u == v) return u;
	for (int k = MX; k >= 0; --k) if (sparse[k][u] != sparse[k][v]) u = sparse[k][u], v = sparse[k][v];
	return par[u];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	graph.resize(n + 1), par.resize(n + 1), depth.resize(n + 1);
	for (auto &i : sparse) i.resize(n + 1);
	par[1] = 1, depth[1] = 1;
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(1, 1);

	for (int i = 1; i <= n; i++) sparse[0][i] = par[i];
	for (int k = 1; k <= MX; k++) for (int i = 1; i <= n; i++) sparse[k][i] = sparse[k - 1][sparse[k - 1][i]];

	int q; cin >> q;
	while (q--) {
		int a, b; cin >> a >> b;
		cout << lca(a, b) << "\n";
	}
}
