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

int n, m;
vector<vi> up, down;
vi vis;

int dfs_up(int u) {
	if (vis[u]) return 0;
	vis[u] = 1;

	int ret = 1;
	for (int v : up[u]) ret += dfs_up(v);
	return ret;
}

int dfs_down(int u) {
	if (vis[u]) return 0;
	vis[u] = 1;

	int ret = 1;
	for (int v : down[u]) ret += dfs_down(v);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	up.resize(n + 1), down.resize(n + 1);

	while (m--) {
		int a, b;
		cin >> a >> b;
		down[a].push_back(b);
		up[b].push_back(a);
	}

	int mid = (n + 1) / 2;

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		vis.assign(n + 1, 0);
		int cnt1 = dfs_up(i);
		vis.assign(n + 1, 0);
		int cnt2 = dfs_down(i);

		ans += cnt1 > mid || cnt2 > mid;
	}

	cout << ans;
}
