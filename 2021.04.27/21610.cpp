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

int n;
int A[50][50];

int oob(int x, int y) {
	return !(0 <= x && x < n && 0 <= y && y < n);
}

pii safe(int x, int y) {
	return {(x + n * 100) % n, (y + n * 100) % n};
}

vpii records = {
		{0,  -1},
		{-1, -1},
		{-1, 0},
		{-1, 1},
		{0,  1},
		{1,  1},
		{1,  0},
		{1,  -1},
};

pii mv(int d, int s, pii xy) {
	--d;
	return safe(xy.first + records[d].first * s, xy.second + records[d].second * s);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> A[i][j];
	vpii clouds = {
			{n - 2, 0},
			{n - 2, 1},
			{n - 1, 0},
			{n - 1, 1}
	};
	while (m--) {
		int d, s;
		cin >> d >> s;
		vpii moved;
		map<pii, int> vis;
		auto chk = [&](int x, int y) {
			return !oob(x, y) && A[x][y];
		};

		for (const auto &a : clouds) {
			auto curr = mv(d, s, a);
			int x = curr.first, y = curr.second;
			++A[x][y];
		}
		for (const auto &a : clouds) {
			auto curr = mv(d, s, a);
			int x = curr.first, y = curr.second;
			A[x][y] += chk(x - 1, y - 1) + chk(x - 1, y + 1) + chk(x + 1, y - 1) + chk(x + 1, y + 1);
			vis[{x, y}] = 1;
		}
		clouds.clear();

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if (!vis.count({i, j}) && A[i][j] >= 2) {
					clouds.emplace_back(i, j);
					A[i][j] -= 2;
				}
			}
	}
	int ans = 0;
	for (const auto &v : A)
		ans += reduce(v, v + 50);
	cout << ans;
}
