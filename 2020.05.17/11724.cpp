#include <bits/stdc++.h>

using namespace std;

vector<int> node(1), cnt;
unordered_map<int, int> mp;

int find(int u) {
	return node[u] != u ? (node[u] = find(node[u])) : u;
}

void merge(int u, int v) {
	if (cnt[u] > cnt[v]) swap(u, v);
	node[find(u)] = find(node[v]);
	cnt[v] += cnt[u];
	cnt[u] = 0;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;

	cnt.assign(n + 1, 1);
	for (int i = 1; i <= n; i++) node.push_back(i);
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		merge(u, v);
	}

	for (int i = 1; i <= n; i++) mp[find(i)] = 1;

	cout << mp.size();
}
