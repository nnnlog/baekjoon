#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;
using namespace views;

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

vi depth;
vpii child;


vi in, par;

int dfs(int u) {
	return (depth[u] = (child[u].first ? dfs(child[u].first) : 0) +
	                   (child[u].second ? dfs(child[u].second) : 0) + 1);
}

vector<vi> ans;

void solve(int u, int start, int end, int dep) {
	if (child[u].first) {
		solve(child[u].first, start, start + depth[child[u].first], dep + 1);
	}
	if (child[u].second) {
		solve(child[u].second, end - depth[child[u].second], end, dep + 1);
	}

	ans[dep].push_back(start + depth[child[u].first] + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	depth.resize(n + 1);
	child.resize(n + 1);
	par.resize(n + 1);
	in.resize(n + 1);
	ans.resize(n + 1);

	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		b = max(b, 0);
		c = max(c, 0);
		child[a] = {b, c};
		if (b) par[b] = a;
		if (c) par[c] = a;

		in[a] = (b > 0) + (c > 0);
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) if (!in[i]) q.push(i);
	int root;
	while (!q.empty()) {
		root = q.front();
		q.pop();
		if (par[root] && !(--in[par[root]])) q.push(par[root]);
	}

	dfs(root);
	solve(root, 0, depth[root], 1);

	for (auto &v : ans) sort(all(v));

	int idx = 1, cnt = 0;
	for (int i = 1; i <= n; i++) {
		auto &v = ans[i];
		if (v.empty()) continue;
		int curr = v.back() - v.front() + 1;
		if (cnt < curr) idx = i, cnt = curr;
	}

	cout << idx << " " << cnt;
}
