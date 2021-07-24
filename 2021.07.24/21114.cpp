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
vpii ans;

vi dfs(int u, int prv) {
	int remain = 0;
	for (int v : graph[u]) {
		if (prv == v) continue;
		auto ret = dfs(v, u);
		if (ret.size() == 2) ans.emplace_back(u, ret[1]);
		else if (remain) ans.emplace_back(ret[0], remain), remain = 0;
		else remain = ret[0];
	}

	vi ret = {u};
	if (remain) ret.push_back(remain);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	graph.resize(n + 1);
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(1, 1);
	cout << ans.size() << "\n";
	for (auto [a, b] : ans) cout << a << " " << b << "\n";
}
