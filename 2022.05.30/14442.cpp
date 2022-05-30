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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;

	vector<vi> vec(n, vi(m));
	for (vi &v : vec) {
		for (int &i : v) {
			char c; cin >> c;
			i = c == '1';
		}
	}

	vector<vector<vi>> dist(n, vector<vi>(m, vi(k + 1, 1e9)));
	queue<pair<int, pair<pii, int>>> Q;
	Q.push({dist[0][0][0] = 1, {{0, 0}, 0}});
	while (!Q.empty()) {
		auto top = Q.front();
		Q.pop();

		int w = top.first, a = top.second.first.first, b = top.second.first.second, c = top.second.second;
		if (dist[a][b][c] < w) continue;

		for (const auto &[dx, dy] : vpii{
				{-1, 0},
				{1, 0},
				{0, -1},
				{0, 1}
		}) {
			int x = a + dx, y = b + dy;
			if (x < 0 || x >= n || y < 0 || y >= m) continue;

			if (!vec[x][y] && dist[x][y][c] > w + 1) Q.push({dist[x][y][c] = w + 1, {{x, y}, c}});
			if (vec[x][y] && c < k && dist[x][y][c + 1] > w + 1 && dist[x][y][c] > w + 1) Q.push({dist[x][y][c + 1] = w + 1, {{x, y}, c + 1}});
		}
	}

	int ans = *min_element(all(dist[n - 1][m - 1]));
	if (ans == 1e9) ans = -1;
	cout << ans;
}
