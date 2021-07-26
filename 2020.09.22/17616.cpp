#include <bits/stdc++.h>

using namespace std;

vector<int> up[100001], down[100001];
int vis_up[100001], vis_down[100001];

int dfs_up(int a) {
	if (vis_up[a]) return 0;
	vis_up[a] = 1;
	int c = 1;
	for (const auto &v : up[a]) c += dfs_up(v);
	return c;
}

int dfs_down(int a) {
	if (vis_down[a]) return 0;
	vis_down[a] = 1;
	int c = 1;
	for (const auto &v : down[a]) c += dfs_down(v);
	return c;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m, x; cin >> n >> m >> x;

	while (m--) {
		int big, small; cin >> big >> small;
		up[small].push_back(big);
		down[big].push_back(small);
	}

	cout << dfs_up(x) << " " << n - dfs_down(x) + 1;
}
