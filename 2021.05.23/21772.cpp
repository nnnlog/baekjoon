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

char mp[101][101];
int ans = 0;
int r, c, t;

void solve(int a, int b, int k, int cnt) {
	ans = max(ans, cnt);
	if (k >= t) return;
	for (auto &[dx, dy] : vpii{
			{-1, 0},
			{1, 0},
			{0, -1},
			{0, 1}
	}) {
		int x = a + dx, y = b + dy;
		if (x < 1 || x > r || y < 1 || y > c) continue;
		if (mp[x][y] == '#') continue;
		int f = mp[x][y] == 'S';
		mp[x][y] = '.';
		solve(x, y, k + 1, cnt + f);
		if (f) mp[x][y] = 'S';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int x, y;
	cin >> r >> c >> t;
	for (int i = 1; i <= r; i++) for (int j = 1; j <= c; j++) {
		cin >> mp[i][j];
		if (mp[i][j] == 'G') x = i, y = j;
	}
	solve(x, y, 0, 0);
	cout << ans;
}
