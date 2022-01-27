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

int vis[100001];
vector<vi> graph;
int dfs(int u) {
	int ret = 1;
	for (int v : graph[u]) {
		if (vis[v]) continue;
		vis[v] = 1;
		ret += dfs(v);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m; cin >> n >> m;
	graph.resize(n + 1);
	while (m--) {
		int a, b; cin >> a >> b;
		graph[b].push_back(a);
	}
	int s; cin >> s;
	vis[s] = 1;
	cout << dfs(s) - 1;
}
