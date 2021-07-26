#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

int grid[51][51];
int dist[51][51];

vector<pii> diff = {
		{1,  0},
		{-1, 0},
		{0,  1},
		{0,  -1}
};

vector<vi> get_template() {
	vector<vi> ret(51, vi(51));
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	pii start, end;

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			char c;
			cin >> c;
			if (c == 'g') grid[i][j] = 1;
			if (c == 'S') start = {i, j};
			if (c == 'F') end = {i, j};
		}

	priority_queue<pair<int, pii>> pq;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			dist[i][j] = 1e9;

	dist[start.first][start.second] = 0;

	pq.push({0, start});


	while (!pq.empty()) {
		auto top = pq.top();
		auto curr_cost = -top.first;
		auto xy = top.second;

		//cout << xy.first << " " << xy.second << " " << curr_cost << "\n";

		pq.pop();

		if (dist[xy.first][xy.second] < curr_cost) continue;

		for (const auto &c : diff) {
			int x = xy.first + c.first, y = xy.second + c.second;
			if (x < 1 || x > n || y < 1 || y > m) continue;
			int nxt = curr_cost;
			if (!grid[x][y])
				for (const auto &cc : diff) {
					int xx = x + cc.first, yy = y + cc.second;
					if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
					if (x == end.first && y == end.second) break;
					if (grid[xx][yy]) {
						++nxt;
						break;
					}
				}
			else nxt += 2500;

			//cout << x << " " << y << " " << trash << " " << near << "\n";

			/*if (dist[x][y].first < trash) continue;
			if (dist[x][y].first == trash && dist[x][y].second < near) continue;*/

			if (dist[x][y] <= nxt) continue;

			dist[x][y] = nxt;
			pq.push({-nxt, {x, y}});
		}
	}

	cout << dist[end.first][end.second] / 2500 << " " << dist[end.first][end.second] % 2500;
}
