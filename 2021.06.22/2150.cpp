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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int v, e; cin >> v >> e;
	vector<vi> graph(v + 1), rev_graph(v + 1);
	while (e--) {
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
		rev_graph[b].push_back(a);
	}
	vi vis(v + 1);
	vi ans;
	stack<int> st;
	function<void(int)> dfs = [&](int u) {
		for (int nxt : graph[u]) if (!vis[nxt]) vis[nxt] = 1, dfs(nxt);
		st.push(u);
	};
	function<void(int)> solve = [&](int u) {
		for (int nxt : rev_graph[u]) if (!vis[nxt]) vis[nxt] = 1, solve(nxt);
		ans.push_back(u);
	};
	for (int i = 1; i <= v; i++) if (!vis[i]) vis[i] = 1, dfs(i);
	int cnt = 0;
	vis.assign(vis.size(), 0);
	map<int, vi> res;
	while (!st.empty()) {
		int u = st.top(); st.pop();
		if (vis[u]) continue;
		++cnt;
		vis[u] = 1;
		ans.clear();
		solve(u);
		sort(all(ans));
		ans.push_back(-1);
		res[ans[0]] = ans;
	}
	cout << cnt << "\n";
	for (const auto &[k, ans] : res) {
		for (int i : ans) cout << i << " ";
		cout << "\n";
	}
}
