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

void bye() {
	cout << "No";
	exit(0);
}

vector<vpll> graph;
vpll info;
vl cost = {0};
ll one = 2e18;
void dfs(int u, ll sum, int prv, int d) {
	//cout << one << " " << u << "\n";
	for (auto [v, w] : graph[u]) {
		if (prv == v) continue;
		ll nxt = -sum + w;
		if (info[v].first) { //cycle check
			if (info[u].first % 2 == info[v].first % 2) {
				ll tmp = w - info[u].second - info[v].second;
				if (abs(tmp) % 2) bye();
				tmp /= 2;
				if (info[u].first % 2 == 0) tmp *= -1;
				//cout << u << " " << v << " " << tmp << "\n";
				if (one < 2e18 && one != tmp) bye();
				one = tmp;
			} else if (info[u].second + info[v].second != w) bye();
		} else info[v] = {d + 1, nxt}, dfs(v, nxt, u, d + 1), cost.emplace_back(d % 2 ? nxt : -nxt);
	}
}

vl ans;
vl vis;
void solve(int u) {
	for (auto [v, w] : graph[u]) {
		if (vis[v]) continue;
		vis[v] = 1;
		ans[v] = w - ans[u];
		solve(v);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m; cin >> n >> m;
	graph.resize(n + 1);
	info.resize(n + 1);
	ans.resize(n + 1);
	vis.resize(n + 1);
	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		graph[a].emplace_back(b, c);
		graph[b].emplace_back(a, c);
	}
	info[1] = {1, 0};
	dfs(1, 0, 1, 1);
	if (one == 2e18) {
		sort(all(cost));
		one = cost[cost.size() / 2];
	}
	ans[1] = one;
	vis[1] = 1;
	solve(1);
	cout << "Yes\n";
	for (int i = 1; i <= n; i++) cout << ans[i] << " ";
}
