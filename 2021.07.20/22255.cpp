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

	int n, m; cin >> n >> m;
	pii S, E;
	cin >> S.first >> S.second >> E.first >> E.second;
	--S.first, --S.second;
	--E.first, --E.second;
	vector<vi> mp(n, vi(m));
	for (auto &v : mp) for (auto &i : v) cin >> i;
	vector<vector<vl>> vis(n, vector<vl>(m, vl(3, 1e18)));
	priority_queue<pair<pll, pii>, vector<pair<pll, pii>>, greater<>> Q;
	vis[S.first][S.second][1] = 0;
	Q.push({{0, 1}, S});

	while (!Q.empty()) {
		auto top = Q.top(); Q.pop();
		int a = top.second.first, b = top.second.second;
		ll v = top.first.first, k = top.first.second;
		if (vis[a][b][k] < v) continue;
		vpii dxdy;
		if (!k) dxdy = {
				{-1, 0},
				{1, 0},
				{0, 1},
				{0, -1},
				};
		else if (k == 1) dxdy = {{-1, 0}, {1, 0}};
		else dxdy = {{0, 1}, {0, -1}};
		++k;
		k %= 3;
		for (const auto &[dx, dy] : dxdy) {
			int x = a + dx, y = b + dy;
			if (x < 0 || x >= n || y < 0 || y >= m) continue;
			if (mp[x][y] == -1) continue;
			ll nxt = v + mp[x][y];
			if (vis[x][y][k] <= nxt) continue;
			vis[x][y][k] = nxt;
			Q.push({{nxt, k}, {x, y}});
		}
	}

	auto tmp = vis[E.first][E.second];
	ll ans = min(tmp[0], min(tmp[1], tmp[2]));
	if (ans == 1e18) ans = -1;
	cout << ans;
}
