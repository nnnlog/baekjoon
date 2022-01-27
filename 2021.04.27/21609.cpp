#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

int n, m;
vector<vi> mp;

void rotate() {
	auto tmp = mp;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			tmp[n - j - 1][i] = mp[i][j];
	mp = tmp;
}

void gravity() {
	for (int i = n - 1; i >= 0; i--)
		for (int j = 0; j < n; j++)
			if (mp[i][j] >= 0) {
				int c = i;
				while (c < n - 1) if (mp[c + 1][j] != -2) break; else ++c;
				mp[c][j] = mp[i][j];
				if (c != i) mp[i][j] = -2;
			}
}

pii bfs(vector<vi> &vis, int i, int j, int remove = 0) {
	pii ret = {1, 0};
	vector<vi> rainbow_vis(n, vi(n));
	queue<pii> q;
	q.push({i, j});
	vis[i][j] = 1;
	while (!q.empty()) {
		auto f = q.front();
		q.pop();
		for (const auto &[dx, dy] : vpii{
				{-1, 0},
				{1,  0},
				{0,  -1},
				{0,  1}
		}) {
			int x = f.first + dx, y = f.second + dy;
			if (x < 0 || y < 0 || x >= n || y >= n || vis[x][y] || rainbow_vis[x][y] || mp[x][y] < 0) continue;
		    if (!mp[x][y]) rainbow_vis[x][y] = 1, ++ret.second;
            else if (mp[x][y] == mp[i][j]) vis[x][y] = 1, q.push({x, y});
			else continue;
            ++ret.first;
            q.push({x, y});
			if (remove) mp[x][y] = -2;
		}
	}
	if (remove) mp[i][j] = -2;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	mp.assign(n, vi(n));

	for (auto &v : mp)
		for (auto &i : v) cin >> i;

	int ans = 0;
	while (1) {
		pii sz, xy;
		vector<vi> vis(n, vi(n));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if (vis[i][j] || mp[i][j] <= 0) continue;
				pii ret = bfs(vis, i, j);
				if (ret.first > sz.first) sz = ret, xy = {i, j};
				else if (ret.first == sz.first && ret.second >= sz.second) sz.second = ret.second, xy = {i, j};
			}
		if (sz.first <= 1) break;
		vis.assign(n, vi(n));
		bfs(vis, xy.first, xy.second, true);
		gravity();
		rotate();
		gravity();
		ans += sz.first * sz.first;
	}
	cout << ans;
}
