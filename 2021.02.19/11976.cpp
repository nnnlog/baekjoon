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

vpii mp[101][101];
int vis[102][102], light[102][102], ans = 1, n, m;

void dfs(int a, int b) {
	if (vis[a][b]) return;
	vis[a][b] = 1;
	for (const auto &[x, y] : mp[a][b]) {
		if (vis[x][y]) continue;
		if (!light[x][y]) ++ans;
		light[x][y] = 1;
		if (vis[x - 1][y] || vis[x + 1][y] || vis[x][y - 1] || vis[x][y + 1]) dfs(x, y);
	}
	for (const auto &[dx, dy] : vpii{
			{-1, 0},
			{0, -1},
			{1, 0},
			{0, 1}
	}) {
		int x = a + dx, y = b + dy;
		if (x < 1 || y < 1 || x > n || y > n) continue;
		if (!vis[x][y] && light[x][y]) dfs(x, y);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	 cin >> n >> m;
	while (m--) {
		int x, y, a, b; cin >> x >> y >> a >> b;
		mp[x][y].emplace_back(a, b);
	}
	light[1][1] = 1;
	dfs(1, 1);
	cout << ans;
}
