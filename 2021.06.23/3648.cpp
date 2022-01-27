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

int Not(int a) {
	return a ^ 1;
}
int True(int a) {
	return a * 2;
}
int False(int a) {
	return a * 2 + 1;
}
int Conv(int a) {
	return a > 0 ? True(a) : False(-a);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while (cin >> ws, !cin.eof()) {
		int n, m; cin >> n >> m;
		vi vis(n * 2 + 2), scc(n * 2 + 2);
		vector<vi> graph(n * 2 + 2);
		auto rev = graph;
		while (m--) {
			int a, b; cin >> a >> b;
			a = Conv(a);
			b = Conv(b);
			graph[Not(a)].push_back(b);
			graph[Not(b)].push_back(a);
			rev[a].push_back(Not(b));
			rev[b].push_back(Not(a));
		}
		stack<int> st;
		function<void(int)> dfs = [&](int u) {
			for (int v : graph[u]) if (!vis[v]) vis[v] = 1, dfs(v);
			st.push(u);
		};
		for (int i = 2; i <= n * 2 + 1; i++) if (!vis[i]) vis[i] = 1, dfs(i);
		int cnt = 0;
		function<void(int)> solve = [&](int u) {
			scc[u] = cnt;
			for (int v : rev[u]) if (!vis[v]) vis[v] = 1, solve(v);
		};
		vis.assign(vis.size(), 0);
		while (!st.empty()) {
			int u = st.top(); st.pop();
			if (vis[u]) continue;
			vis[u] = 1;
			solve(u);
			++cnt;
		}
		int f = 1;
		for (int i = 1; i <= n; i++) {
			if (scc[True(i)] == scc[False(i)]) {
				f = 0;
				break;
			}
		}
		cout << (f && scc[True(1)] > scc[False(1)] ? "yes" : "no") << "\n";
	}
}
