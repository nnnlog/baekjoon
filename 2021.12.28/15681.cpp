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
vi ans;
int dfs(int u, int prv) {
	int ret = 1;
	for (int v : graph[u]) if (v != prv) ret += dfs(v, u);
	return ans[u] = ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, r, q; cin >> n >> r >> q;
	graph.resize(n + 1), ans.resize(n + 1);
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(r, -1);
	while (q--) {
		int a; cin >> a;
		cout << ans[a] << "\n";
	}
}
