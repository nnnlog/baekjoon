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

vld cost;
ld sum = 0, cnt = 0;

vector<vi> graph;

void dfs(int u, int prv) {
	int child = 0;
	for (const auto &v: graph[u]) {
		if (v == prv) continue;
		child++;
	}
	if (!child) {
		sum += cost[u];
		cnt++;
		return;
	}
	cost[u] /= child;
	for (const auto &v: graph[u]) {
		if (v == prv) continue;
		cost[v] = cost[u];
		dfs(v, u);
	}
	cost[u] = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, w;
	cin >> n >> w;
	graph.resize(n + 1);
	cost.resize(n + 1);
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	cost[1] = w;
	dfs(1, 0);

	cout << fixed;
	cout.precision(16);

	cout << sum / cnt;
}
