#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

vector<pii> direct = {
		{1,  0},
		{0,  1},
		{-1, 0},
		{0,  -1}
};

vector<queue<pair<pii, pii>>> q;
int vis[101][101], mp[101][101], island[101][101], n, num = 1;

void dfs(int x, int y) {
	if (!island[x][y]) {
		island[x][y] = num;
		q.back().push({{x, y},
		               {0, num}});
	}

	for (const auto &mv : direct) {
		int xx = x + mv.first, yy = y + mv.second;
		if (xx < 0 || yy < 0 || xx >= n || yy >= n || island[xx][yy]) continue;
		if (mp[xx][yy]) {
			island[xx][yy] = num;
			q.back().push({{xx, yy},
			               {0, num}});
			dfs(xx, yy);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> mp[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (!island[i][j] && mp[i][j]) q.emplace_back(), dfs(i, j), ++num;
		}


	for (int i = 0; i < n; i++) {
		//for (int j = 0; j < n; j++) cout << island[i][j] << " ";
		//cout << "\n";
	}

	int ans = 1e9;
	for (int i = 1; i < num; i++) {
		
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++) vis[j][k] = 0;

		auto &rq = q[i - 1];
		int f = 0;
		while (!rq.empty() && !f) {
			auto xy = rq.front();
			rq.pop();
			for (const auto &mv : direct) {
				int x = xy.first.first + mv.first, y = xy.first.second + mv.second;
				if (x < 0 || x >= n || y < 0 || y >= n) continue;
				//cout << x << " " << y << "\n";
				if (island[x][y] && island[x][y] != xy.second.second) {
					ans = min(ans, xy.second.first);
					f = 1;
					break;
				}
				if (!vis[x][y]) {
					vis[x][y] = 1;
					rq.push({{x, y}, {xy.second.first + 1, xy.second.second}});
				}
			}
		}
	}

	cout << ans;
}
