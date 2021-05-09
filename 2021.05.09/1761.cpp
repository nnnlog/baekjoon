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

vector<vpii> graph;
vi par, depth, weight;
pii sparse[17][40001];

void dfs(int a, int d) {
	for (const auto &[nxt, w] : graph[a]) if (!depth[nxt]) depth[nxt] = d, par[nxt] = a, weight[nxt] = w, dfs(nxt, d + 1);
}

int lca(int a, int b) {
	if (depth[a] < depth[b]) swap(a, b);
	if (depth[a] != depth[b]) {
		int diff = depth[a] - depth[b];
		for (int i = 16; i >= 0; --i) if (diff & (1 << i)) a = sparse[i][a].first;
	}
	if (a == b) return a;
	for (int i = 16; i >= 0; --i) {
		int x = sparse[i][a].first, y = sparse[i][b].first;
		if (x != y) a = x, b = y;
	}
	return par[a];
}

int get(int a, int b) {
	if (depth[a] < depth[b]) swap(a, b); //b가 조상 노드가 되도록
	int ret = 0;
	int diff = depth[a] - depth[b];
	for (int i = 16; i >= 0; --i) if (diff & (1 << i)) ret += sparse[i][a].second, a = sparse[i][a].first;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	graph.resize(n + 1), par.resize(n + 1), depth.resize(n + 1), weight.resize(n + 1);
	for (int i = 1; i < n; i++) {
		int a, b, w; cin >> a >> b >> w;
		graph[a].emplace_back(b, w);
		graph[b].emplace_back(a, w);
	}
	depth[1] = 1;
	dfs(1, 2);
	for (int j = 1; j <= n; j++) sparse[0][j] = {par[j], weight[j]};
	for (int i = 1; i <= 16; i++) for (int j = 1; j <= n; j++) sparse[i][j] = {
			sparse[i - 1][sparse[i - 1][j].first].first,
			sparse[i - 1][j].second + sparse[i - 1][sparse[i - 1][j].first].second,
	};
	int q; cin >> q;
	while (q--) {
		int a, b; cin >> a >> b;
		int l = lca(a, b);
		cout << get(a, l) + get(b, l) << "\n";
	}
}
