#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef unordered_map<int, int> mpii;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	vi deg(n);
	vector<set<int>> graph(n), o;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		--a, --b;
		graph[a].insert(b);
		graph[b].insert(a);
		++deg[a];
		++deg[b];
	}
	o = graph;

	queue<int> q;
	for (int i = 0; i < n; i++)
		if (deg[i] == 1) q.push(i);

	while (!q.empty()) {
		auto u = q.front(); q.pop();
		int v = *graph[u].begin();
		graph[u].clear();
		graph[v].erase(u);
		--deg[u], --deg[v];
		if (deg[v] == 1) q.push(v);
	}

	auto is_cycle = [&](auto i) {
		return deg[i] > 0;
	};

	graph = o;
	vi ans(n);
	for (int u = 0; u < n; u++) {
		if (!is_cycle(u)) continue;
		if (ans[u]) continue;
		queue<pii> q;
		q.push({u, 0});
		while (!q.empty()) {
			auto v = q.front(); q.pop();
			for (const auto &nxt : graph[v.first]) {
				if (is_cycle(nxt)) continue;
				if (ans[nxt]) continue;
				ans[nxt] = v.second + 1;
				q.push({nxt, ans[nxt]});
			}
		}
	}

	for (const auto &i : ans) cout << i << " ";
}
