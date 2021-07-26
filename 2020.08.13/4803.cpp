#include <bits/stdc++.h>

using namespace std;

int UF[501];

void init(int size) {
	for (int i = 1; i <= size; i++) UF[i] = i;
}

int find(int x) {
	return UF[x] = UF[x] == x ? x : find(UF[x]);
}

bool merge(int a, int b) {
	if (find(a) == find(b)) return false;
	UF[find(a)] = find(b);
	return true;
}

int main() {
	//cin.tie(0)->sync_with_stdio(0);
	//cout.tie(0);

	int n = 1, m = 1, T = 1;
	scanf("%d %d", &n, &m);
	do {
		init(n);

		unordered_map<int, bool> invalid_tree_init, invalid_tree;
		while (m--) {
			int u, v; cin >> u >> v;
			if (!merge(u, v)) invalid_tree_init[u] = 1;
		}

		for (const auto &pair : invalid_tree_init) invalid_tree[find(pair.first)] = 1;

		unordered_map<int, bool> vis;
		int ans = 0;
		for (int i = 1; i <= n; i++)
			if (!vis[find(i)] && !invalid_tree[find(i)]) {
				vis[find(i)] = 1;
				ans++;
			}

		cout << "Case " << T++ << ": ";
		if (!ans) cout << "No trees.";
		else if (ans == 1) cout << "There is one tree.";
		else cout << "A forest of " << ans << " trees.";
		cout << "\n";

		scanf("%d %d", &n, &m);
	} while (n || m);
}
