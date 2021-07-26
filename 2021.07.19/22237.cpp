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

int r, c;
char mp[1000][1000];
pair<pii, char> vis[3000][3000];
int N = 1e9, E = -1e9, W = 1e9, S = -1e9;
pii home;
vpii block;
vector<pair<pii, char>> dxdy = {
		{{-1, 0}, 'U'},
		{{1, 0}, 'D'},
		{{0, -1}, 'L'},
		{{0, 1}, 'R'},
};

int invalid(int x, int y) {
	return x < 0 || x >= r || y < 0 || y >= c;
}
int valid(int x, int y) {
	return !invalid(x, y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

		cin >> r >> c;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++) {
				cin >> mp[i][j];
				if (mp[i][j] == '#') block.emplace_back(i, j);
				if (mp[i][j] == 'T') {
					N = min(N, i);
					E = max(E, j);
					W = min(W, j);
					S = max(S, i);
				}
				if (mp[i][j] == 'H') home = {i, j};
			}

	/*	r = 1000, c = 1000;
		N = E = W = S = 999;
		home = {0, 0};
		mp[999][999] = 'T';
		*/
	queue<pii> Q;
	vis[0][0] = {{1, 1}, 1};
	Q.push({0, 0});
	while (!Q.empty()) {
		auto top = Q.front(); Q.pop();
		for (const auto &[xy, cmd] : dxdy) {
			int nxtX = top.first + xy.first, nxtY = top.second + xy.second;
			if (invalid(N + nxtX, 0) || invalid(S + nxtX, 0) || invalid(0, E + nxtY) || invalid(0, W + nxtY)) continue;
			//if (invalid(home.first - nxtX, home.second - nxtY)) continue;
			if (vis[nxtX + 1500][nxtY + 1500].second) continue;
			vis[nxtX + 1500][nxtY + 1500] = {{top.first, top.second}, cmd};
			int f = 0;
			for (const auto &[a, b] : block)
				if (valid(a - nxtX, b - nxtY) && mp[a - nxtX][b - nxtY] == 'T') {
					f = 1;
					break;
				}
			if (f) continue;
			if (valid(home.first - nxtX, home.second - nxtY) && mp[home.first - nxtX][home.second - nxtY] == 'T') {
				int x = nxtX, y = nxtY;
				string ans;
				while (x || y) {
					auto info = vis[x + 1500][y + 1500];
					ans.push_back(info.second);
					x = info.first.first, y = info.first.second;
					//cout << x << " " <<y<<"\n";
				}
				reverse(all(ans));
				cout << ans;
				return 0;
			}
			Q.push({nxtX, nxtY});
		}
	}

	cout << -1;
}
