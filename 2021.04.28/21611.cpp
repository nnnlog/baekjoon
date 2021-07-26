#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

int n, m;
int mp[49][49];
pii prv[49][49];

vpii direction = {
		{-1, 0},
		{1, 0},
		{0, -1},
		{0, 1}
};

void init() {
	int vis[49][49] = {0,};
	int x = 0, y = 0;
	int dx = 0, dy = 1;
	vis[0][0] = 1;
	prv[0][0] = {-1, -1};
	while (x != n / 2 || y != n / 2) {
		int nxtX = x + dx, nxtY = y + dy;
		if (nxtX < 0 || nxtX >= n || nxtY < 0 || nxtY >= n || vis[nxtX][nxtY]) {
			if (!dx && dy == 1) dx = 1, dy = 0;
			else if (dx == 1 && !dy) dx = 0, dy = -1;
			else if (!dx && dy == -1) dx = -1, dy = 0;
			else dx = 0, dy = 1;
		} else prv[nxtX][nxtY] = {x, y}, x = nxtX, y = nxtY, vis[x][y] = 1;
	}
}

void mv(int &x, int &y) {
	pii &a = prv[x][y];
	x = a.first, y = a.second;
}

void refill() {
	int x = n / 2, y = n / 2;
	mv(x, y);
	while (x >= 0 && y >= 0) {
		if (!mp[x][y]) {
			int a = x, b = y;
			mv(a, b);
			int f = 0;
			while (a >= 0 && b >= 0) {
				if (mp[a][b]) {
					mp[x][y] = mp[a][b];
					mp[a][b] = 0;
					f = 1;
					break;
				}
				mv(a, b);
			}
			if (!f) return;
		}
		mv(x, y);
	}
}

int ans = 0;

int grouping(int x, int y, int set_zero = 0) {
	int curr = mp[x][y], cnt = 0;
	if (!curr) return 0;
	while (x >= 0 && y >= 0) {
		if (curr == mp[x][y]) ++cnt;
		else break;
		if (set_zero) mp[x][y] = 0;
		mv(x, y);
	}
	return cnt;
}

void explode() {
	int x = n / 2, y = n / 2;
	mv(x, y);
	while (x >= 0 && y >= 0) {
		int cnt = grouping(x, y);
		if (cnt >= 4)  {
			ans += mp[x][y] * cnt;
			grouping(x, y, 1);
			refill();
			x = n / 2, y = n / 2;
		}
		mv(x, y);
	}
	return;
}

void transition() {
	vi vec;
	int x = n / 2, y = n / 2;
	mv(x, y);
	while (x >= 0 && y >= 0) {
		int curr = mp[x][y];
		if (curr) {
			int cnt = grouping(x, y, 1);
			vec.emplace_back(cnt);
			vec.emplace_back(curr);
		}
		mv(x, y);
	}
	x = n / 2, y = n / 2;
	mv(x, y);
	reverse(all(vec));
	while (x >= 0 && y >= 0 && !vec.empty()) {
		mp[x][y] = vec.back();
		vec.pop_back();
		mv(x, y);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	init();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> mp[i][j];
	while (m--) {
		int d, s; cin >> d >> s;
		--d;
		for (int i = 1; i <= s; i++) {
			int x = n / 2 + direction[d].first * i, y = n / 2 + direction[d].second * i;
			mp[x][y] = 0;
		}
		refill();
		explode();
		transition();
	}
	cout << ans;
}
